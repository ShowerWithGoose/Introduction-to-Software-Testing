package frontend;

import error.Error;
import error.ErrorType;
import node.*;
import node.Character;
import node.Number;
import token.Token;
import token.TokenType;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * ClassName: Parser
 * Package: frontend
 * Description:
 *
 * @Author
 * @Create 2024/10/4 9:41
 * @Version 1.0
 */
public class Parser {
    public static Parser parser = new Parser();

    private List<Token> tokens;

    private Integer index = 0;

    private Integer indexBackup = 0;

    // now
    private Token token = null;


    public CompUnit compUnit = null;

    private void setTokens(List<Token> tokens) {
        this.tokens = tokens;
        this.token = tokens.get(index);
    }


    private void nextToken() {
        index++;
        if (index < tokens.size()) {
            token = tokens.get(index);
        } else {
            token = null;
        }
    }

    private boolean isEOF() {
        return token == null;
    }

    private void backup() {
        indexBackup = index;
    }

    private void recover() {
        index = indexBackup;
        if (index < tokens.size()) {
            token = tokens.get(index);
        } else {
            token = null;
        }
    }

    // to prevent token is null (come to file end), use getTokenType() instead of token.type
    private TokenType getTokenType() {
        if (token != null) {
            return token.type;
        } else {
            return null;
        }
    }

    // to prevent pre-read token is null
    private TokenType getPreReadTokenType(Integer offset) { // offset = 0 is the same as token
        if (index + offset < tokens.size()) {
            return tokens.get(index + offset).type;
        } else {
            return null;
        }
    }

    public void parse(List<Token> tokens) {
        setTokens(tokens);
        this.compUnit = parseCompUnit();
        Error.errors.sort(Comparator.comparingInt(e -> e.lineNo));
    }

    private CompUnit parseCompUnit() {
        // CompUnit -> {Decl} {FuncDef} MainFuncDef
        List<Decl> decls = null;
        List<FuncDef> funcDefs = null;
        MainFuncDef mainFuncDef = null;

        // 默认程序完整性，即preReadToken(2)不会越界为null
        // while 不满足的，注意死循环的问题，问题常常出现在token为null时
        while (!isEOF() && getPreReadTokenType(2) != TokenType.LPARENT
                && getPreReadTokenType(1) != TokenType.MAINTK) {
            // 只要满足进入循环的条件，就一定会有decls
            if (decls == null) {
                decls = new ArrayList<>();
            }
            decls.add(parseDecl());
        }
        // MAINTK 认为是进入了MainFuncDef
        while (!isEOF() && getPreReadTokenType(1) != TokenType.MAINTK) {
            if(funcDefs == null){
                funcDefs = new ArrayList<>();
            }
            funcDefs.add(parseFuncDef());
        }
        mainFuncDef = parseMainFuncDef();
        return new CompUnit(decls, funcDefs, mainFuncDef);
    }

    private Decl parseDecl() {
        // Decl -> ConstDecl | VarDecl
        ConstDecl constDecl = null;
        VarDecl varDecl = null;

        if (getTokenType() == TokenType.CONSTTK) {
            // ConstDecl
            constDecl = parseConstDecl();
            if (constDecl != null) {
                return new Decl(constDecl);
            }
        } else {
            varDecl = parseVarDecl();
            if (varDecl != null) {
                return new Decl(varDecl);
            }
        }
        return null;
    }

    private VarDecl parseVarDecl() {
        // VarDecl -> BType VarDef { ',' VarDef } ';'
        BType bType = null;
        List<VarDef> varDefs = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token semicnToken = null;
        bType = parseBType();
        varDefs.add(parseVarDef());
        while (getTokenType() == TokenType.COMMA) {
            commas.add(token);
            nextToken();
            varDefs.add(parseVarDef());
        }
        if (getTokenType() == TokenType.SEMICN) {
            semicnToken = token;
            nextToken();
        } else {
            // error i
            Error error = new Error();
            error.lineNo = varDefs.get(varDefs.size() - 1).lineNo;
            error.type = ErrorType.i;
            Error.errors.add(error);

            // fix error
            semicnToken = new Token(";", TokenType.SEMICN, -1, -1);

        }
        return new VarDecl(bType, varDefs, commas, semicnToken);
    }

    private VarDef parseVarDef() {
        // VarDef => Ident[ '[' ConstExp ']' ] | Ident[ '[' ConstExp ']' ] '=' InitVal
        // VarDef => Ident[ '[' ConstExp ']' ] ('=' InitVal | ε)
        Token ident = null;

        Token lbrack = null;
        ConstExp constExp = null;
        Token rbrack = null;

        Token assign = null;
        InitVal initVal = null;

        if (getTokenType() == TokenType.IDENFR) {
            ident = token;
            nextToken();
            if (getTokenType() == TokenType.LBRACK) {
                lbrack = token;
                nextToken();
                constExp = parseConstExp();
                if (getTokenType() == TokenType.RBRACK) {
                    rbrack = token;
                    nextToken();
                } else {
                    // error k
                    Error error = new Error();
                    error.lineNo = constExp.lineNo;
                    error.type = ErrorType.k;
                    Error.errors.add(error);

                    // fix error
                    Token fixToken = new Token();
                    fixToken.content = "]";
                    fixToken.type = TokenType.RBRACK;
                    fixToken.lineNo = error.lineNo;
                    rbrack = fixToken;
                }
            }
            if (getTokenType() == TokenType.ASSIGN) {
                assign = token;
                nextToken();
                initVal = parseInitVal();
            }
            System.out.println("not return null");
            return new VarDef(ident, lbrack, constExp, rbrack, assign, initVal);
        } else {
            // error
            System.out.println("return null what?");
            return null;
        }

    }

    private InitVal parseInitVal() {
        // InitVal => Exp | '{' Exp {',' Exp} '}' | StringConst
        List<Exp> exps = new ArrayList<>();

        Token lbrace = null;
        List<Token> commas = new ArrayList<>();
        Token rbrace = null;

        Token stringConst = null;

        if (getTokenType() == TokenType.LBRACE) {
            lbrace = token;
            nextToken();
            exps.add(parseExp());
            while (getTokenType() == TokenType.COMMA) {
                commas.add(token);
                nextToken();
                exps.add(parseExp());
            }
            if (getTokenType() == TokenType.RBRACE) {
                rbrace = token;
                nextToken();
                return new InitVal(lbrace, exps, commas, rbrace);
            } else {
                // error
                return null;
            }
        } else if (getTokenType() == TokenType.STRCON) {
            stringConst = token;
            nextToken();
            return new InitVal(stringConst);
        } else {
            exps.add(parseExp());
            return new InitVal(exps);
        }
    }

    private FuncDef parseFuncDef() {
        // FuncDef => FuncType Ident '(' [FuncFParams] ')' Block
        FuncType funcType = null;
        Token ident = null;
        Token lparent = null;
        FuncFParams funcFParams = null;
        Token rparent = null;
        Block block = null;

        funcType = parseFuncType();
        if (getTokenType() == TokenType.IDENFR) {
            ident = token;
            nextToken();
            if (getTokenType() == TokenType.LPARENT) {
                lparent = token;
                nextToken();
                if (getTokenType() != TokenType.RPARENT) {
                    funcFParams = parseFuncFParams();
                }
                if (getTokenType() == TokenType.RPARENT) {
                    rparent = token;
                    nextToken();
                    // Block
                    block = parseBlock();
                    return new FuncDef(funcType, ident, lparent, funcFParams, rparent, block);
                } else {
                    // error j
                    Error error = new Error();
                    if (funcFParams != null) {
                        error.lineNo = funcFParams.lineNo;
                    } else {
                        error.lineNo = funcType.lineNo;
                    }
                    error.type = ErrorType.j;
                    Error.errors.add(error);


                    // fix error
                    Token fixToken = new Token();
                    fixToken.content = ")";
                    fixToken.type = TokenType.RPARENT;
                    fixToken.lineNo = error.lineNo;
                    rparent = fixToken;
                    block = parseBlock();
                    return new FuncDef(funcType, ident, lparent, funcFParams, rparent, block);
                }
            } else {
                // error
                return null;
            }
        } else {
            // error
            return null;
        }
    }

    private Block parseBlock() {
        // Block -> '{' {BlockItem} '}'
        Token lbrace = null;
        List<BlockItem> blockItems = new ArrayList<>();
        Token rbrace = null;

        if (getTokenType() == TokenType.LBRACE) {
            lbrace = token;
            nextToken();
            while (getTokenType() != null && getTokenType() != TokenType.RBRACE) {
                blockItems.add(parseBlockItem());
            }
            if (getTokenType() == null) { // 程序终止，例如int main(){ 未闭合
                // error
                return null;
            }
            rbrace = token;
            nextToken();
            return new Block(lbrace, blockItems, rbrace);
        } else {
            // error
            return null;
        }
    }

    private BlockItem parseBlockItem() {
        // BlockItem -> Decl | Stmt
        Decl decl = null;
        Stmt stmt = null;
        if (getTokenType() == TokenType.CONSTTK || getTokenType() == TokenType.INTTK || getTokenType() == TokenType.CHARTK) {
            decl = parseDecl();
            return new BlockItem(decl);
        } else {
            stmt = parseStmt();
            return new BlockItem(stmt);
        }
    }

    private Stmt parseStmt() {
        // 容易识别的用规则，不容易识别的用回溯
        // 递归前记录index, 递归后恢复index
        // 递归过程中出现不匹配，可能是error，也可能是需要回溯
        // Stmt =>
        // | Block // '{' {BlockItem} '}'
        // | 'if' '(' Cond ')' Stmt ['else' Stmt]
        // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        // | 'break' ';' | 'continue' ';' | 'return' [Exp] ';'
        // | 'printf' '(' StringConst { ',' Exp} ')' ';'

        // LVal '=' Exp ';'
        // | LVal '=' 'getint' '(' ')' ';'
        // | LVal '=' 'getchar' '(' ')' ';'
        // | [Exp] ';'
        LVal lVal = null;
        Token assign = null;
        List<Exp> exps = new ArrayList<>();
        List<Token> semicns = new ArrayList();
        List<Token> commas = new ArrayList();
        Block block = null;
        Token ifToken = null;
        Token forToken = null;
        Token breakToken = null;
        Token continueToken = null;
        Token returnToken = null;
        Token printfToken = null;
        Token stringConst = null;
        Token lparent = null;
        Cond cond = null;
        Token rparent = null;
        Token elseToken = null;
        Stmt stmt = null;
        Stmt ifStmt = null;
        Stmt elseStmt = null;
        ForStmt forStmt1 = null;
        ForStmt forStmt2 = null;

        if (getTokenType() == TokenType.LBRACE) {
            block = parseBlock();
            return new Stmt(block);
        }
        // 'if'
        else if (getTokenType() == TokenType.IFTK) {
            ifToken = token;
            nextToken();
            if (getTokenType() == TokenType.LPARENT) {
                lparent = token;
                nextToken();
                cond = parseCond();
                if (getTokenType() == TokenType.RPARENT) {
                    rparent = token;
                    nextToken();
                } else {
                    // error j
                    Error error = new Error();
                    error.lineNo = cond.lineNo;
                    error.type = ErrorType.j;
                    Error.errors.add(error);

                    // fix error
                    rparent = new Token(")", TokenType.RPARENT, -1, -1);
                }
                ifStmt = parseStmt();
                if (getTokenType() == TokenType.ELSETK) {
                    elseToken = token;
                    nextToken();
                    elseStmt = parseStmt();
                }
                return new Stmt(ifToken, lparent, cond, rparent, ifStmt, elseToken, elseStmt);
            } else {
                // error
                return null;
            }
        }

        // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        else if (getTokenType() == TokenType.FORTK) {
            forToken = token;
            nextToken();
            if (getTokenType() == TokenType.LPARENT) {
                lparent = token;
                nextToken();
                if (getTokenType() != TokenType.SEMICN) {
                    forStmt1 = parseForStmt();
                }
                if (getTokenType() == TokenType.SEMICN) { // ';'
                    semicns.add(token);
                    nextToken();
                    if (getTokenType() != TokenType.SEMICN) {
                        cond = parseCond();
                    }
                    if (getTokenType() == TokenType.SEMICN) { // ';'
                        semicns.add(token);
                        nextToken();
                        if (getTokenType() != TokenType.RPARENT) {
                            forStmt2 = parseForStmt();
                        }
                        if (getTokenType() == TokenType.RPARENT) {
                            rparent = token;
                            nextToken();
                            stmt = parseStmt();
                            return new Stmt(forToken, lparent, forStmt1, semicns, cond, forStmt2, rparent, stmt);
                        }
                        // missing ')'
                        else {
                            // error
                            return null;
                        }
                    }
                    // missing the second semicolon
                    else {
                        // error
                        return null;
                    }
                }
                // missing the first semicolon
                else {
                    // error
                    return null;
                }
            }
        }

        // 'break' ';'
        else if (getTokenType() == TokenType.BREAKTK) {
            breakToken = token;
            nextToken();
            if (getTokenType() == TokenType.SEMICN) {
                semicns.add(token);
                nextToken();
            } else {
                // error
                Error error = new Error();
                error.lineNo = breakToken.lineNo;
                error.type = ErrorType.i;
                Error.errors.add(error);
                semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
            }
            return new Stmt(breakToken, semicns);
        }

        // 'continue' ';'
        else if (getTokenType() == TokenType.CONTINUETK) {
            continueToken = token;
            nextToken();
            if (getTokenType() == TokenType.SEMICN) {
                semicns.add(token);
                nextToken();
            } else {
                // error i
                Error error = new Error();
                error.lineNo = continueToken.lineNo;
                error.type = ErrorType.i;
                Error.errors.add(error);
                semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
            }
            return new Stmt(continueToken, semicns);
        }

        // 'return' [Exp] ';'
        else if (getTokenType() == TokenType.RETURNTK) {
            returnToken = token;
            nextToken();
            if (getTokenType() != TokenType.SEMICN) {
                // todo: exist: exps.add(null);
                exps.add(parseExp());
                System.out.println(exps.size());
                System.out.println(exps.get(0));
                System.out.println(token.getPrintInfo());
                System.out.println(getPreReadTokenType(1));
            }
            if (getTokenType() == TokenType.SEMICN) {
                semicns.add(token);
                nextToken();
            } else {
                // error i
                // todo: patch the missing ;
                Error error = new Error();
                if (exps.size() > 0 && exps.get(exps.size() - 1) != null) {
                    error.lineNo = exps.get(exps.size() - 1).lineNo;
                } else {
                    error.lineNo = returnToken.lineNo;
                }
                error.type = ErrorType.i;
                Error.errors.add(error);
                semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
            }
            return new Stmt(returnToken, semicns, exps);
        }

        // 'printf' '(' StringConst {',' Exp} ')' ';'
        else if (getTokenType() == TokenType.PRINTFTK) {
            printfToken = token;
            nextToken();
            if (getTokenType() == TokenType.LPARENT) {
                lparent = token;
                nextToken();
                if (getTokenType() == TokenType.STRCON) {
                    stringConst = token;
                    nextToken();
                    while (getTokenType() == TokenType.COMMA) {
                        commas.add(token);
                        nextToken();
                        exps.add(parseExp());
                    }
                    if (getTokenType() == TokenType.RPARENT) {
                        rparent = token;
                        nextToken();
                    } else {
                        // error j
                        Error error = new Error();
                        if (exps.size() > 0 && exps.get(exps.size() - 1) != null) {
                            error.lineNo = exps.get(exps.size() - 1).lineNo;
                        } else {
                            error.lineNo = printfToken.lineNo;
                        }
                        error.type = ErrorType.j;
                        Error.errors.add(error);
                        rparent = new Token(")", TokenType.RPARENT, -1, -1);
                    }
                    if (getTokenType() == TokenType.SEMICN) {
                        semicns.add(token);
                        nextToken();
                    } else {
                        // error i
                        Error error = new Error();
                        if (exps.size() > 0 && exps.get(exps.size() - 1) != null) {
                            error.lineNo = exps.get(exps.size() - 1).lineNo;
                        } else {
                            error.lineNo = printfToken.lineNo;
                        }
                        error.type = ErrorType.i;
                        Error.errors.add(error);
                        semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
                    }
                    return new Stmt(printfToken, lparent, stringConst, commas, exps, rparent, semicns);
                } else {
                    // error
                    return null;
                }

            }
        } else {
            Stmt tryStmt = new Stmt();
            backup();
            System.out.println("try parse GetCharStmt");
            if (tryParseGetCharStmt(tryStmt)) {
                return tryStmt;
            } else {
                recover();
                tryStmt = new Stmt();
                System.out.println("try parse GetIntStmt");
                if (tryParseGetIntStmt(tryStmt)) {
                    return tryStmt;
                } else {
                    recover();
                    tryStmt = new Stmt();
                    System.out.println("try parse LValExpStmt");
                    if (tryParseLValExpStmt(tryStmt)) {
                        return tryStmt;
                    } else {
                        recover();
                        tryStmt = new Stmt();
                        System.out.println("try parse ExpStmt");
                        // 需要最后匹配，因为Exp包括LVal
                        if (tryParseExpStmt(tryStmt)) {
                            return tryStmt;
                        } else {
                            // error
                            return null;
                        }
                    }
                }
            }
        }

        return null;
    }

    private Boolean tryParseLValExpStmt(Stmt stmt) {
        // LVal '=' Exp ';'
        stmt.lVal = parseLVal();
        if (stmt.lVal == null || getTokenType() != TokenType.ASSIGN) {
            return false;
        }
        stmt.lineNo = stmt.lVal.lineNo;
        stmt.assign = token;
        nextToken();
        List<Exp> exps = new ArrayList<>();

        exps.add(parseExp());
        if (exps.get(0) == null) {
            if (stmt.lineNo == 86) {
                System.out.println(86);
                System.out.println(token.content);
            }
            return false;
        }
        stmt.exps = exps;
        List<Token> semicns = new ArrayList<>();
        // error i
        if (getTokenType() != TokenType.SEMICN) {
            Error error = new Error();
            error.lineNo = exps.get(0).lineNo;
            error.type = ErrorType.i;
            Error.errors.add(error);

            // fix error
            Token fixToken = new Token();
            fixToken.content = ";";
            fixToken.type = TokenType.SEMICN;
            fixToken.lineNo = error.lineNo;
            semicns.add(fixToken);

        } else {
            semicns.add(token);
            nextToken();
        }
        stmt.semicns = semicns;
        stmt.type = StmtType.LValExpStmt;
        return true;
    }

    private Boolean tryParseGetIntStmt(Stmt stmt) {
        // LVal '=' 'getint' '(' ')' ';'
        stmt.lVal = parseLVal();
        if (stmt.lVal == null || getTokenType() != TokenType.ASSIGN) {
            return false;
        }
        stmt.lineNo = stmt.lVal.lineNo;
        stmt.assign = token;
        nextToken();
        if (getTokenType() != TokenType.GETINTTK) {
            return false;
        }
        stmt.getIntToken = token;
        nextToken();
        if (getTokenType() != TokenType.LPARENT) {
            return false;
        }
        stmt.lparent = token;
        nextToken();
        // 都走到这里了，说明try成功了
        if (getTokenType() != TokenType.RPARENT) {
            Error error = new Error();
            error.lineNo = stmt.lVal.lineNo;
            error.type = ErrorType.j;
            Error.errors.add(error);
            stmt.rparent = new Token(")", TokenType.RPARENT, -1, -1);
        } else {
            stmt.rparent = token;
            nextToken();
        }
        List<Token> semicns = new ArrayList<>();
        if (getTokenType() != TokenType.SEMICN) {
            Error error = new Error();
            error.lineNo = stmt.lVal.lineNo;
            error.type = ErrorType.i;
            Error.errors.add(error);
            semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
        } else {
            semicns.add(token);
            nextToken();
        }
        stmt.semicns = semicns;
        stmt.type = StmtType.GetIntStmt;
        return true;
    }

    private Boolean tryParseGetCharStmt(Stmt stmt) {
        // LVal '=' 'getchar' '(' ')' ';'
        stmt.lVal = parseLVal();
        if (stmt.lVal == null || getTokenType() != TokenType.ASSIGN) {
            return false;
        }
        stmt.lineNo = stmt.lVal.lineNo;
        stmt.assign = token;
        nextToken();
        if (getTokenType() != TokenType.GETCHARTK) {
            return false;
        }
        stmt.getCharToken = token;
        nextToken();
        if (getTokenType() != TokenType.LPARENT) {
            return false;
        }
        stmt.lparent = token;
        nextToken();
        if (getTokenType() != TokenType.RPARENT) {
            Error error = new Error();
            error.lineNo = stmt.lVal.lineNo;
            error.type = ErrorType.j;
            Error.errors.add(error);
            stmt.rparent = new Token(")", TokenType.RPARENT, -1, -1);
        } else {
            stmt.rparent = token;
            nextToken();
        }
        List<Token> semicns = new ArrayList<>();
        if (getTokenType() != TokenType.SEMICN) {
            Error error = new Error();
            error.lineNo = stmt.lVal.lineNo;
            error.type = ErrorType.i;
            Error.errors.add(error);
            semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
        } else {
            semicns.add(token);
            nextToken();
        }
        stmt.semicns = semicns;
        stmt.type = StmtType.GetCharStmt;
        return true;
    }

    private Boolean tryParseExpStmt(Stmt stmt) {
        // [Exp] ';'
        List<Exp> exps = new ArrayList<>();
        List<Token> semicns = new ArrayList<>();
        if (getTokenType() != TokenType.SEMICN) {
            exps.add(parseExp());
        }
        if (getTokenType() != TokenType.SEMICN
                && exps.size() > 0 && exps.get(0) != null) { // 缺少分号一定有Exp
            Error error = new Error();
            if (exps.get(0) != null) {
                error.lineNo = exps.get(0).lineNo;
                error.type = ErrorType.i;
                Error.errors.add(error);
                semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
                stmt.exps = exps;
                stmt.semicns = semicns;
                stmt.type = StmtType.ExpStmt;
            }
        } else {
            if (exps.size() == 0) {
                System.out.println(token.lineNo);
                System.out.println(token.content);
                System.out.println(tokens.get(index + 1).content);
            }
            if (exps.size() > 0 && exps.get(0) != null) {
                stmt.lineNo = exps.get(0).lineNo;
            } else {
                stmt.lineNo = token.lineNo;
            }
            semicns.add(token);
            nextToken();
            stmt.exps = exps;
            stmt.semicns = semicns;
            stmt.type = StmtType.ExpStmt;
        }
        return true;
    }

    private ForStmt parseForStmt() {
        // ForStmt => LVal '=' Exp
        LVal lVal = null;
        Token assign = null;
        Exp exp = null;

        lVal = parseLVal();
        if (getTokenType() == TokenType.ASSIGN) {
            assign = token;
            nextToken();
            exp = parseExp();
            return new ForStmt(lVal, assign, exp);
        } else {
            // error
            return null;
        }
    }

    private Cond parseCond() {
        // Cond -> LOrExp
        LOrExp lOrExp = parseLOrExp();
        if (lOrExp == null) {
            return null;
        }
        return new Cond(lOrExp);
    }

    private LOrExp parseLOrExp() {
        // LOrExp -> LAndExp | LOrExp '||' LAndExp
        LAndExp lAndExp = null;
        Token or = null;
        LOrExp lOrExp = null;

        lAndExp = parseLAndExp();
        if (getTokenType() == TokenType.OR) {
            or = token;
            nextToken();
            lOrExp = parseLOrExp();
        }
        if (lAndExp == null) {
            return null;
        }
        return new LOrExp(lAndExp, or, lOrExp);
    }

    private LAndExp parseLAndExp() {
        // LAndExp -> EqExp | LAndExp '&&' EqExp
        EqExp eqExp = null;
        Token and = null;
        LAndExp lAndExp = null;

        eqExp = parseEqExp();
        if (getTokenType() == TokenType.AND) {
            and = token;
            nextToken();
            lAndExp = parseLAndExp();
        }
        if (eqExp == null) {
            return null;
        }
        return new LAndExp(eqExp, and, lAndExp);
    }

    private EqExp parseEqExp() {
        // EqExp -> RelExp | EqExp ('==' | '!=') RelExp
        RelExp relExp = null;
        Token op = null;
        EqExp eqExp = null;

        relExp = parseRelExp();
        if (getTokenType() == TokenType.EQL || getTokenType() == TokenType.NEQ) {
            op = token;
            nextToken();
            eqExp = parseEqExp();
        }
        if (relExp == null) {
            return null;
        }
        return new EqExp(relExp, op, eqExp);
    }

    private RelExp parseRelExp() {
        // RelExp -> AddExp | RelExp ('>' | '<' | '>=' | '<=') AddExp
        AddExp addExp = null;
        Token op = null;
        RelExp relExp = null;

        addExp = parseAddExp();
        if (getTokenType() == TokenType.LSS || getTokenType() == TokenType.LEQ || getTokenType() == TokenType.GRE || getTokenType() == TokenType.GEQ) {
            op = token;
            nextToken();
            relExp = parseRelExp();
        }
        if (addExp == null) {
            return null;
        }
        return new RelExp(addExp, op, relExp);
    }

    private FuncType parseFuncType() {
        // FuncType => 'void' | 'int' | 'char'
        Token typeToken = null;
        if (getTokenType() == TokenType.VOIDTK
                || getTokenType() == TokenType.INTTK
                || getTokenType() == TokenType.CHARTK) {
            typeToken = token;
            nextToken();
            return new FuncType(typeToken);
        } else {
            // error
            return null;
        }
    }

    private FuncFParams parseFuncFParams() {
        // FuncFParams => FuncFParam { ',' FuncFParam }
        List<FuncFParam> funcFParams;
        List<Token> commas = null;
        FuncFParam funcFParam = parseFuncFParam();
        if (funcFParam == null) { // 没有形参，返回null
            return null;
        }
        funcFParams = new ArrayList<>();
        funcFParams.add(funcFParam);
        while (getTokenType() == TokenType.COMMA) {
            if (commas == null) {
                commas = new ArrayList<>();
            }
            commas.add(token);
            nextToken();
            funcFParams.add(parseFuncFParam());
        }
        return new FuncFParams(funcFParams, commas);
    }

    private FuncFParam parseFuncFParam() {
        // FuncFParam => BType Ident [ '[' ']' ]
        BType bType = null;
        Token ident = null;
        Token lbrack = null;
        Token rbrack = null;

        bType = parseBType();
        if (getTokenType() == TokenType.IDENFR) {
            ident = token;
            nextToken();
            if (getTokenType() == TokenType.LBRACK) {
                lbrack = token;
                nextToken();
                if (getTokenType() == TokenType.RBRACK) {
                    rbrack = token;
                    nextToken();
                } else {
                    // error k
                    Error error = new Error();
                    error.lineNo = bType.lineNo;
                    error.type = ErrorType.k;
                    Error.errors.add(error);

                    // fix error
                    Token fixToken = new Token();
                    fixToken.content = "]";
                    fixToken.type = TokenType.RBRACK;
                    fixToken.lineNo = error.lineNo;
                    rbrack = fixToken;
                }
            }
            return new FuncFParam(bType, ident, lbrack, rbrack);
        } else {
            // error
            return null;
        }
    }

    private MainFuncDef parseMainFuncDef() {
        // MainFuncDef => 'int' 'main' '(' ')' Block
        Token intToken = null;
        Token mainToken = null;
        Token lparen = null;
        Token rparen = null;
        Block block = null;

        if (getTokenType() == TokenType.INTTK) {
            intToken = token;
            nextToken();
            if (getTokenType() == TokenType.MAINTK) {
                mainToken = token;
                nextToken();
                if (getTokenType() == TokenType.LPARENT) {
                    lparen = token;
                    nextToken();
                    if (getTokenType() == TokenType.RPARENT) {
                        rparen = token;
                        nextToken();
                        block = parseBlock();
                        return new MainFuncDef(intToken, mainToken, lparen, rparen, block);
                    } else {
                        // error j
                        Error error = new Error();
                        error.lineNo = intToken.lineNo;
                        error.type = ErrorType.j;
                        Error.errors.add(error);

                        // fix error
                        Token fixToken = new Token();
                        fixToken.content = ")";
                        fixToken.type = TokenType.RPARENT;
                        fixToken.lineNo = error.lineNo;
                        rparen = fixToken;
                        block = parseBlock();
                        return new MainFuncDef(intToken, mainToken, lparen, rparen, block);
                    }
                } else {
                    // error
                    return null;
                }
            } else {
                // error
                return null;
            }
        } else {
            // error
            return null;
        }
    }

    private ConstDecl parseConstDecl() {
        // ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
        Token constToken = null;
        BType bType = null;
        List<ConstDef> constDefs = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token semicnToken = null;

        if (getTokenType() == TokenType.CONSTTK) {
            // 'const'
            constToken = token;
            nextToken();
            // BType
            bType = parseBType();

            // ConstDef
            constDefs.add(parseConstDef());

            // { ',' ConstDef }
            while (getTokenType() == TokenType.COMMA) {
                commas.add(token);
                nextToken();
                constDefs.add(parseConstDef());
            }
            // ';'
            if (getTokenType() == TokenType.SEMICN) {
                semicnToken = token;
                nextToken();
            } else {
                // error i
                Error error = new Error();
                error.lineNo = constDefs.get(constDefs.size() - 1).lineNo;
                error.type = ErrorType.i;
                Error.errors.add(error);

                // fix error i
                semicnToken = new Token(";", TokenType.SEMICN, -1, -1);
            }
            return new ConstDecl(constToken, bType, constDefs, commas, semicnToken);
        } else {
            // error
            return null;
        }

    }


    private BType parseBType() {
        Token typeToken = null;
        if (getTokenType() == TokenType.INTTK) {
            typeToken = token;
            nextToken();
            return new BType(typeToken);
        } else if (getTokenType() == TokenType.CHARTK) {
            typeToken = token;
            nextToken();
            return new BType(typeToken);
        } else {
            // error
            return null;
        }
    }

    private ConstDef parseConstDef() {
        // ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        Token ident = null;
        Token lbrack = null;
        Token rbrack = null;
        Token assign = null;
        ConstExp constExp = null;
        ConstInitVal constInitVal = null;
        if (getTokenType() == TokenType.IDENFR) {
            // Ident
            ident = token;
            nextToken();
            // [ '[' ConstExp ']' ]
            if (getTokenType() == TokenType.LBRACK) {
                lbrack = token;
                nextToken();
                constExp = parseConstExp();
                if (getTokenType() == TokenType.RBRACK) {
                    rbrack = token;
                    nextToken();
                } else {
                    // error k
                    Error error = new Error();
                    error.lineNo = constExp.lineNo;
                    error.type = ErrorType.k;
                    Error.errors.add(error);

                    // fix error
                    Token fixToken = new Token();
                    fixToken.content = "]";
                    fixToken.type = TokenType.RBRACK;
                    fixToken.lineNo = error.lineNo;
                    rbrack = fixToken;
                }
            }
            // '='
            if (getTokenType() == TokenType.ASSIGN) {
                assign = token;
                nextToken();
                // ConstInitVal
                constInitVal = parseConstInitVal();
                return new ConstDef(ident, constExp, constInitVal, lbrack, rbrack, assign);
            } else {
                // error
                return null;
            }

        } else {
            // error
            return null;
        }

    }

    private ConstInitVal parseConstInitVal() {
        // ConstInitVal -> ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        List<ConstExp> constExps = new ArrayList<>();
        List<Token> commas = new ArrayList<>();
        Token lbrace = null;
        Token rbrace = null;
        Token stringConst = null;
        // ConstInitVal -> '{' [ ConstExp { ',' ConstExp } ] '}'
        if (getTokenType() == TokenType.LBRACE) {
            lbrace = token;
            nextToken();
            if (getTokenType() != TokenType.RBRACE) {
                constExps.add(parseConstExp());
                while (getTokenType() == TokenType.COMMA) {
                    commas.add(token);
                    nextToken();
                    constExps.add(parseConstExp());
                }
            }
            if (getTokenType() == TokenType.RBRACE) {
                rbrace = token;
                nextToken();
                return new ConstInitVal(lbrace, constExps, commas, rbrace);
            } else {
                // error
                return null;
            }
        } else if (getTokenType() == TokenType.STRCON) { // StringConst
            stringConst = token;
            nextToken();
            return new ConstInitVal(stringConst);
        } else { // ConstExp
            System.out.println(getTokenType());
            constExps.add(parseConstExp());
            return new ConstInitVal(constExps);
        }
    }

    private ConstExp parseConstExp() {
        AddExp addExp = parseAddExp();
        if (addExp == null) {
            return null;
        }
        return new ConstExp(addExp);
    }

    private AddExp parseAddExp() {
        // AddExp -> MulExp | AddExp ('+' | '−') MulExp
        // 消除和右递归一样，建树方式都是“错的”
        // AddExp -> MulExp | MulExp ('+' | '−') AddExp // 右递归
        // AddExp -> MulExp (('+' | '−') AddExp | ε) // 建树方式，但打印不是这么打印的
        // AddExp -> MulExp {('+' | '−') MulExp} // 消除
        // 打印的时候<MulExp>， 如果到下一个for(出现了递归)，就打印<AddExp>，否则打印空

        MulExp mulExp = null;
        Token op = null;
        AddExp addExp = null;

        mulExp = parseMulExp();
        if (getTokenType() == TokenType.PLUS
                || getTokenType() == TokenType.MINU) {
            op = token;
            nextToken();
            addExp = parseAddExp();
        }
        if (mulExp == null) {
            return null;
        }
        return new AddExp(mulExp, addExp, op);
    }

    private MulExp parseMulExp() {
        UnaryExp unaryExp = null;
        Token op = null;
        MulExp mulExp = null;

        unaryExp = parseUnaryExp();
        if (getTokenType() == TokenType.MULT
                || getTokenType() == TokenType.DIV
                || getTokenType() == TokenType.MOD) {
            op = token;
            nextToken();
            mulExp = parseMulExp();
        }
        if (unaryExp == null) {
            return null;
        }
        return new MulExp(unaryExp, op, mulExp);
    }

    private UnaryExp parseUnaryExp() {
        // UnaryExp - > PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        PrimaryExp primaryExp = null;
        Token ident = null;
        Token lparent = null;
        Token rparent = null;
        FuncRParams funcRParams = null;
        UnaryOp unaryOp = null;
        UnaryExp unaryExp = null;

        // UnaryExp -> Ident '(' [FuncRParams] ')' // 调用函数
        if (getTokenType() == TokenType.IDENFR
                && getPreReadTokenType(1) == TokenType.LPARENT) {
            ident = token;
            nextToken();
            // todo: duplicate code
            if (getTokenType() == TokenType.LPARENT) {
                lparent = token;
                nextToken();

                // FuncRParams (optional)
                if (getTokenType() != TokenType.RPARENT) {
                    funcRParams = parseFuncRParams();
//                    System.out.println(funcRParams);
                }

                if (getTokenType() == TokenType.RPARENT) {
                    rparent = token;
                    nextToken();
                    return new UnaryExp(ident, lparent, rparent, funcRParams);
                } else {
                    // error j
                    Error error = new Error();
                    // 行号有错
                    if (funcRParams != null) {
                        error.lineNo = funcRParams.lineNo;
                    } else {
                        error.lineNo = ident.lineNo;
                    }
                    error.type = ErrorType.j;
                    Error.errors.add(error);
                    return new UnaryExp(ident, lparent,
                            new Token(")", TokenType.LPARENT, -1, -1), funcRParams);
                }
            } else {
                // error
                return null;
            }
        }
        // UnaryExp -> UnaryOp UnaryExp
        else if (getTokenType() == TokenType.PLUS
                || getTokenType() == TokenType.MINU
                || getTokenType() == TokenType.NOT) {
            // UnaryExp -> UnaryOp UnaryExp
            unaryOp = parseUnaryOp();
            unaryExp = parseUnaryExp();
            return new UnaryExp(unaryOp, unaryExp);
        } else { // UnaryExp -> PrimaryExp
            Token now = token;
            primaryExp = parsePrimaryExp();
//            if (primaryExp == null){
//                System.out.println("*&*******" + now.content);
//                System.out.println(tokens.get(index + 1).content);
//            }
            if (primaryExp == null) {
                return null;
            }
            return new UnaryExp(primaryExp);
        }

    }

    private FuncRParams parseFuncRParams() {
        // FuncRParams -> Exp { ',' Exp }
        // 函数可能没有实参，对应返回值为null，而且如果只有一个实参，commas为null
        List<Exp> exps;
        List<Token> commas = null;
        Exp exp = parseExp();
        if (exp == null) {
            return null;
        }
        exps = new ArrayList<>();
        exps.add(exp);
        while (getTokenType() == TokenType.COMMA) {
            if (commas == null) {
                commas = new ArrayList<>();
            }
            commas.add(token);
            nextToken();
            exps.add(parseExp());
        }
        return new FuncRParams(exps, commas);
    }

    private Exp parseExp() {
        // Exp -> AddExp
        AddExp addExp = parseAddExp();
        if (addExp == null) {
            return null;
        } else {
            return new Exp(addExp);
        }
    }

    private UnaryOp parseUnaryOp() {
        // UnaryOp -> '+' | '-' | '!'
        Token op = null;
        if (getTokenType() == TokenType.PLUS
                || getTokenType() == TokenType.MINU
                || getTokenType() == TokenType.NOT) {
            op = token;
            nextToken();
            return new UnaryOp(op);
        } else {
            // error
            return null;
        }
    }

    private PrimaryExp parsePrimaryExp() {
        // PrimaryExp -> '(' Exp ')' | LVal | Number | Character
        Token lparent = null;
        Token rparent = null;
        Exp exp = null;
        LVal lVal = null;
        Number number = null;
        Character character = null;
        // PrimaryExp -> '(' Exp ')'
        if (getTokenType() == TokenType.LPARENT) {
            lparent = token;
            nextToken();
            exp = parseExp();
            if (getTokenType() == TokenType.RPARENT) {
                rparent = token;
                nextToken();
                if (exp == null) {
                    return null;
                }
                return new PrimaryExp(lparent, rparent, exp);
            } else {
                // error j
                Error error = new Error();
                error.lineNo = exp.lineNo;
                error.type = ErrorType.j;
                Error.errors.add(error);
                return null;
            }
        } else if (getTokenType() == TokenType.IDENFR) { // LVal
            lVal = parseLVal();
            if (lVal == null) {
                return null;
            }
            return new PrimaryExp(lVal);
        } else if (getTokenType() == TokenType.INTCON) { // Number
            number = parseNumber();
            if (number == null) {
                return null;
            }
            return new PrimaryExp(number);

        } else if (getTokenType() == TokenType.CHRCON) { // Character
            character = parseCharacter();
            if (character == null) {
                return null;
            }
            return new PrimaryExp(character);

        } else {
            // error
            return null;
        }

    }

    private Character parseCharacter() {
        Token charConst = null;
        if (getTokenType() == TokenType.CHRCON) {
            charConst = token;
            nextToken();
            return new Character(charConst);
        } else {
            // error
            return null;
        }
    }

    private LVal parseLVal() {
        // LVal -> Ident [ '[' Exp ']' ]
        Token ident = null;
        Token lbrack = null;
        Exp exp = null;
        Token rbrack = null;
        if (getTokenType() == TokenType.IDENFR) {
            ident = token;
            nextToken();
            if (getTokenType() == TokenType.LBRACK) {
                lbrack = token;
                nextToken();
                exp = parseExp();
                if (getTokenType() == TokenType.RBRACK) {
                    rbrack = token;
                    nextToken();
                } else {
                    // error k
                    if (!Error.isExist(exp.lineNo, ErrorType.k)) {
                        Error.errors.add(new Error(exp.lineNo, ErrorType.k));
                    }
                    // fix it
                    return new LVal(ident, lbrack, exp,
                            new Token("]", TokenType.RBRACK, -1, -1));
                }
            }
            return new LVal(ident, lbrack, exp, rbrack);
        } else {
            // error
            return null;
        }
    }

    private Number parseNumber() {
        Token intcon = null;
        if (getTokenType() == TokenType.INTCON) {
            intcon = token;
            nextToken();
            return new Number(intcon);
        } else {
            // error
            return null;
        }

    }

}
