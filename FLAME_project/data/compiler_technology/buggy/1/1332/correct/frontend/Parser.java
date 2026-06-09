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
            if (funcDefs == null) {
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
        List<VarDef> varDefs = null;
        List<Token> commas = null;
        Token semicnToken = null;
        bType = parseBType();
        if (bType == null) {
            return null;
        }
        VarDef varDef = parseVarDef();
        if (varDef == null) {
            return null;
        }
        varDefs = new ArrayList<>();
        varDefs.add(varDef);
        while (getTokenType() == TokenType.COMMA) {
            if (commas == null) {
                commas = new ArrayList<>();
            }
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
                if (constExp == null) {
                    return null;
                }
                if (getTokenType() == TokenType.RBRACK) {
                    rbrack = token;
                    nextToken();
                } else {
                    // error k
                    Error.errors.add(new Error(constExp.lineNo, ErrorType.k));

                    // fix error
                    rbrack = new Token("]", TokenType.RBRACK, -1, -1);
                }
            }
            if (getTokenType() == TokenType.ASSIGN) {
                assign = token;
                nextToken();
                initVal = parseInitVal();
                if (initVal == null) {
                    return null;
                }
            }
            return new VarDef(ident, lbrack, constExp, rbrack, assign, initVal);
        } else {
            return null;
        }

    }

    private InitVal parseInitVal() {
        // InitVal => Exp | '{' [Exp {',' Exp}] '}' | StringConst
        Exp exp = null;

        Token lbrace = null;
        List<Exp> exps = null;
        List<Token> commas = null;
        Token rbrace = null;

        Token stringConst = null;

        // '{' [Exp {',' Exp}] '}'
        if (getTokenType() == TokenType.LBRACE) {
            lbrace = token;
            nextToken();
            if (getTokenType() != TokenType.RBRACE) {
                exp = parseExp();
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
                // 从while中出来时不是, 说明是}
            }
            rbrace = token;
            nextToken();
            return new InitVal(lbrace, exps, commas, rbrace);
        }
        // StringConst
        else if (getTokenType() == TokenType.STRCON) {
            stringConst = token;
            nextToken();
            return new InitVal(stringConst);
        }
        // Exp
        else {
            exp = parseExp();
            if (exp == null) {
                return null;
            }
            return new InitVal(exp);
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
        if (funcType == null) {
            return null;
        }
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
                } else {
                    // error j
                    Error error = new Error();
                    if (funcFParams != null) {
                        error.lineNo = funcFParams.lineNo;
                    } else {
                        error.lineNo = lparent.lineNo;
                    }
                    error.type = ErrorType.j;
                    Error.errors.add(error);


                    // fix error
                    rparent = new Token(")", TokenType.RPARENT, -1, -1);
                }
                // Block
                block = parseBlock();
                return new FuncDef(funcType, ident, lparent, funcFParams, rparent, block);
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
        List<BlockItem> blockItems = null;
        Token rbrace = null;

        if (getTokenType() == TokenType.LBRACE) {
            lbrace = token;
            nextToken();
            while (!isEOF() && getTokenType() != TokenType.RBRACE) {
                BlockItem blockItem = parseBlockItem();
                if (blockItems == null) {
                    blockItems = new ArrayList<>();
                }
                blockItems.add(blockItem);
            }
            if (isEOF()) { // 程序终止，例如int main(){ 未闭合
                // error
                throw new RuntimeException("EOF when parse block");
            }
            rbrace = token;
            nextToken();
            return new Block(lbrace, blockItems, rbrace);
        } else {
            return null;
        }
    }

    private BlockItem parseBlockItem() {
        // BlockItem -> Decl | Stmt
        Decl decl = null;
        Stmt stmt = null;
        if (getTokenType() == TokenType.CONSTTK
                || getTokenType() == TokenType.INTTK || getTokenType() == TokenType.CHARTK) {
            decl = parseDecl();
            return new BlockItem(decl);
        } else {
            stmt = parseStmt();
            if (stmt == null) {
                throw new RuntimeException("parse stmt error when parse '" + token.content + "' in line" + token.lineNo);
            }
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
        List<Exp> exps = null;
        Exp exp = null;
        List<Token> semicns = null;
        Token semicn = null;
        List<Token> commas = null;
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

        boolean isMissingFirstSemicn = false;

        if (getTokenType() == TokenType.LBRACE) {
            block = parseBlock();
            return new Stmt(block);
        }
        // | 'if' '(' Cond ')' Stmt ['else' Stmt]
        else if (getTokenType() == TokenType.IFTK) {
            ifToken = token;
            nextToken();
            if (getTokenType() == TokenType.LPARENT) {
                lparent = token;
                nextToken();
                cond = parseCond();
                if (cond == null) {
                    // 及时return null
                    return null;
                }
                if (getTokenType() == TokenType.RPARENT) {
                    rparent = token;
                    nextToken();
                } else {
                    // error j
                    Error.errors.add(new Error(cond.lineNo, ErrorType.j));

                    // fix error
                    rparent = new Token(")", TokenType.RPARENT, -1, -1);
                }
                ifStmt = parseStmt();
                if (ifStmt == null) {
                    return null;
                }
                if (getTokenType() == TokenType.ELSETK) {
                    elseToken = token;
                    nextToken();
                    elseStmt = parseStmt();
                    if (elseStmt == null) {
                        return null;
                    }
                }
                return new Stmt(ifToken, lparent, cond, rparent, ifStmt, elseToken, elseStmt);
            } else {
                // 有 if 没 左括号
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
                    // 备份此时位置
                    backup();
                    forStmt1 = parseForStmt(); // optional
                    // 下面的if语句是用来修复 forStmt1为空同时没有第一个; 的情况，即此时是cond
//                    if(forStmt1 == null){
//                        recover();
////                        System.out.println("forStmt1 is null");
//                        backup();
//                        cond = parseCond();
//                        if(cond != null){
//                            System.out.println("forStmt1 is null, cond is not null");
//                            isMissingFirstSemicn = true;
//                            recover();
//                        }
//                    }
                }
                semicns = new ArrayList<>();
                if (getTokenType() == TokenType.SEMICN) { // ';'
                    semicns.add(token);
                    nextToken();
                } else {// missing the first semicolon
                    // error
                    throw new RuntimeException("no ;");

                    // 下面是修复缺少第一个;的代码，取消注释的同时需要注释掉上面的throw
//                    // fix
//                    int lineNo;
//                    if (forStmt1 != null) {
//                        lineNo = forStmt1.lineNo;
//                    } else {
//                        lineNo = lparent.lineNo;
//                    }
//                    Error.errors.add(new Error(lineNo, ErrorType.i));
//                    semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
                }
                // the second ;
                if (getTokenType() != TokenType.SEMICN) {
                    cond = parseCond(); // optional
                }
                if (getTokenType() == TokenType.SEMICN) { // ';'
                    semicns.add(token);
                    nextToken();
                } else {// missing the second semicolon
                    // error
                    throw new RuntimeException("no ;");

                    // 下面是修复缺少第二个;的代码，取消注释的同时需要注释掉上面的throw
//                    // fix
//                    int lineNo;
//                    if (cond != null) {
//                        lineNo = cond.lineNo;
//                    } else {
//                        lineNo = semicns.get(0).lineNo;
//                    }
//                    Error.errors.add(new Error(lineNo, ErrorType.i));
//                    semicns.add(new Token(";", TokenType.SEMICN, -1, -1));
                }
                if (getTokenType() != TokenType.RPARENT) {
                    forStmt2 = parseForStmt(); // optional
                }
                if (getTokenType() == TokenType.RPARENT) {
                    rparent = token;
                    nextToken();
                } else {// missing ')'
                    // error
                    throw new RuntimeException("no )");

                    // 下面是修复缺少)的代码，取消注释的同时需要注释掉上面的throw
//                    // fix
//                    int lineNo;
//                    if(forStmt2 != null) {
//                        lineNo = forStmt2.lineNo;
//                    }else{
//                        lineNo = semicns.get(semicns.size() - 1).lineNo;
//                    }
//                    Error.errors.add(new Error(lineNo, ErrorType.j));
//                    rparent = new Token(")", TokenType.RPARENT, -1, -1);
                }
                stmt = parseStmt();
                return new Stmt(forToken, lparent, forStmt1, semicns, cond, forStmt2, rparent, stmt);

            }else{
                // missing '('
                return null;
            }
        }

        // 'break' ';'
        else if (getTokenType() == TokenType.BREAKTK) {
            breakToken = token;
            nextToken();
            if (getTokenType() == TokenType.SEMICN) {
                semicn = token;
                nextToken();
            } else {
                // error
                Error.errors.add(new Error(breakToken.lineNo, ErrorType.i));
                semicn = new Token(";", TokenType.SEMICN, -1, -1);
            }
            return new Stmt(breakToken, semicn);
        }

        // 'continue' ';'
        else if (getTokenType() == TokenType.CONTINUETK) {
            continueToken = token;
            nextToken();
            if (getTokenType() == TokenType.SEMICN) {
                semicn = token;
                nextToken();
            } else {
                // error i
                Error.errors.add(new Error(continueToken.lineNo, ErrorType.i));
                semicn = new Token(";", TokenType.SEMICN, -1, -1);
            }
            return new Stmt(continueToken, semicn);
        }

        // 'return' [Exp] ';'
        else if (getTokenType() == TokenType.RETURNTK) {
            returnToken = token;
            nextToken();
            if (getTokenType() != TokenType.SEMICN) {
                exp = parseExp();
            }
            if (getTokenType() == TokenType.SEMICN) {
                semicn = token;
                nextToken();
            } else {
                // error i
                Error error = new Error();
                if (exp != null) {
                    error.lineNo = exp.lineNo;
                } else {
                    error.lineNo = returnToken.lineNo;
                }
                error.type = ErrorType.i;
                Error.errors.add(error);
                semicn = new Token(";", TokenType.SEMICN, -1, -1);
            }
            return new Stmt(returnToken, semicn, exp);
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
                        if (commas == null) {
                            commas = new ArrayList<>();
                        }
                        commas.add(token);
                        nextToken();
                        if (exps == null) {
                            exps = new ArrayList<>();
                        }
                        exps.add(parseExp());
                    }
                    if (getTokenType() == TokenType.RPARENT) {
                        rparent = token;
                        nextToken();
                    } else {
                        // error j missing )
                        Error error = new Error();
                        if (exps != null) {
                            error.lineNo = exps.get(exps.size() - 1).lineNo;
                        } else {
                            error.lineNo = stringConst.lineNo;
                        }
                        error.type = ErrorType.j;
                        Error.errors.add(error);
                        rparent = new Token(")", TokenType.RPARENT, -1, -1);
                    }
                    if (getTokenType() == TokenType.SEMICN) {
                        semicn = token;
                        nextToken();
                    } else {
                        // error i missing ;
                        // 同一行只会有一个错误，所以这里行号选择)的行号
                        Error.errors.add(new Error(rparent.lineNo, ErrorType.i));
                        semicn = new Token(";", TokenType.SEMICN, -1, -1);
                    }
                    return new Stmt(printfToken, lparent, stringConst, commas, exps, rparent, semicn);
                } else {
                    // error
                    return null;
                }

            }
        }

        // try
        else {
            Stmt tryStmt = new Stmt();
            backup();
//            System.out.println("try parse GetCharStmt");
            if (tryParseGetCharStmt(tryStmt)) {
                return tryStmt;
            } else {
                // 恢复token
                recover();
                // 重置 stmt
                tryStmt = new Stmt();
//                System.out.println("try parse GetIntStmt");
                if (tryParseGetIntStmt(tryStmt)) {
                    return tryStmt;
                } else {
                    recover();
                    tryStmt = new Stmt();
//                    System.out.println("try parse LValExpStmt");
                    if (tryParseLValExpStmt(tryStmt)) {
                        return tryStmt;
                    } else {
                        recover();
                        tryStmt = new Stmt();
//                        System.out.println("try parse ExpStmt");
                        // 需要最后匹配，因为Exp包括LVal
                        if (tryParseExpStmt(tryStmt)) {
                            return tryStmt;
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

        Exp exp = parseExp();
        if (exp == null) {
            return false;
        }
        stmt.exp = exp;
        // error i
        if (getTokenType() != TokenType.SEMICN) {
            Error.errors.add(new Error(stmt.exp.lineNo, ErrorType.i));

            // fix error
            stmt.semicn = new Token(";", TokenType.SEMICN, -1, -1);

        } else {
            stmt.semicn = token;
            nextToken();
        }
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
            Error.errors.add(new Error(stmt.lparent.lineNo, ErrorType.j));
            stmt.rparent = new Token(")", TokenType.RPARENT, -1, -1);
        } else {
            stmt.rparent = token;
            nextToken();
        }
        if (getTokenType() != TokenType.SEMICN) {
            Error.errors.add(new Error(stmt.rparent.lineNo, ErrorType.i));
            stmt.semicn = new Token(";", TokenType.SEMICN, -1, -1);
        } else {
            stmt.semicn = token;
            nextToken();
        }
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
            // 错误行号为 (
            Error.errors.add(new Error(stmt.lparent.lineNo, ErrorType.j));
            stmt.rparent = new Token(")", TokenType.RPARENT, -1, -1);
        } else {
            stmt.rparent = token;
            nextToken();
        }
        if (getTokenType() != TokenType.SEMICN) {
            Error.errors.add(new Error(stmt.rparent.lineNo, ErrorType.i));
            stmt.semicn = new Token(";", TokenType.SEMICN, -1, -1);
        } else {
            stmt.semicn = token;
            nextToken();
        }
        stmt.type = StmtType.GetCharStmt;
        return true;
    }

    private Boolean tryParseExpStmt(Stmt stmt) {
        // [Exp] ';'
        // 前面都没匹配，这是最后一个stmt尝试，总要匹配
        // 注意stmt的空白构造方法没有设置行号，需要自己设置
        Exp exp = null;
        Token semicn = null;
        if (getTokenType() == TokenType.SEMICN) {
            semicn = token;
            nextToken();
            stmt.lineNo = semicn.lineNo;
        } else {
            exp = parseExp();
            if (exp == null) {
                return false;
            }
            if (getTokenType() == TokenType.SEMICN) {
                semicn = token;
                nextToken();
            } else {
                Error.errors.add(new Error(exp.lineNo, ErrorType.i));
                semicn = new Token(";", TokenType.SEMICN, -1, -1);
            }
            stmt.lineNo = exp.lineNo;
        }
        stmt.exp = exp;
        stmt.semicn = semicn;
        stmt.type = StmtType.ExpStmt;
        return true;
    }

    private ForStmt parseForStmt() {
        // ForStmt => LVal '=' Exp
        LVal lVal = null;
        Token assign = null;
        Exp exp = null;

        lVal = parseLVal();
        if (lVal == null) {
            return null;
        }
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
        // LOrExp => LAndExp | LAndExp '||' LOrExp // 右递归
        LAndExp lAndExp = null;
        Token or = null;
        LOrExp lOrExp = null;

        lAndExp = parseLAndExp();
        if (lAndExp == null) {
            return null;
        }
        if (getTokenType() == TokenType.OR) {
            or = token;
            nextToken();
            lOrExp = parseLOrExp();
        }
        return new LOrExp(lAndExp, or, lOrExp);
    }

    private LAndExp parseLAndExp() {
        // LAndExp -> EqExp | LAndExp '&&' EqExp
        // LAmdExp => EqExp | EqExp '&&' LAndExp // 右递归
        EqExp eqExp = null;
        Token and = null;
        LAndExp lAndExp = null;

        eqExp = parseEqExp();
        if (eqExp == null) {
            return null;
        }
        if (getTokenType() == TokenType.AND) {
            and = token;
            nextToken();
            lAndExp = parseLAndExp();
        }
        return new LAndExp(eqExp, and, lAndExp);
    }

    private EqExp parseEqExp() {
        // EqExp -> RelExp | EqExp ('==' | '!=') RelExp
        // EqExp => RelExp | RelExp ('==' | '!=') EqExp // 右递归
        RelExp relExp = null;
        Token op = null;
        EqExp eqExp = null;

        relExp = parseRelExp();
        if (relExp == null) {
            return null;
        }
        if (getTokenType() == TokenType.EQL || getTokenType() == TokenType.NEQ) {
            op = token;
            nextToken();
            eqExp = parseEqExp();
        }
        return new EqExp(relExp, op, eqExp);
    }

    private RelExp parseRelExp() {
        // RelExp -> AddExp | RelExp ('>' | '<' | '>=' | '<=') AddExp
        // RelExp => AddExp | AddExp ('<' | '>' | '<=' | '>=') RelExp // 右递归
        AddExp addExp = null;
        Token op = null;
        RelExp relExp = null;

        addExp = parseAddExp();
        if (addExp == null) {
            return null;
        }
        if (getTokenType() == TokenType.LSS || getTokenType() == TokenType.LEQ || getTokenType() == TokenType.GRE || getTokenType() == TokenType.GEQ) {
            op = token;
            nextToken();
            relExp = parseRelExp();
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
        if (bType == null) {
            return null;
        }
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
                    Error.errors.add(new Error(lbrack.lineNo, ErrorType.k));

                    // fix error
                    rbrack = new Token("]", TokenType.RBRACK, -1, -1);
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
                    } else {
                        // error j
                        Error.errors.add(new Error(lparen.lineNo, ErrorType.j));

                        // fix error
                        rparen = new Token(")", TokenType.RPARENT, -1, -1);
                    }
                    block = parseBlock();
                    return new MainFuncDef(intToken, mainToken, lparen, rparen, block);
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
        List<ConstDef> constDefs = null;
        List<Token> commas = null;
        Token semicnToken = null;

        if (getTokenType() == TokenType.CONSTTK) {
            // 'const'
            constToken = token;
            nextToken();
            // BType
            bType = parseBType();
            if (bType == null) {
                return null;
            }

            ConstDef constDef = null;
            constDef = parseConstDef();
            if (constDef == null) {
                return null;
            }
            constDefs = new ArrayList<>();
            // ConstDef
            constDefs.add(constDef);

            // { ',' ConstDef }
            while (getTokenType() == TokenType.COMMA) {
                if (commas == null) {
                    commas = new ArrayList<>();
                }
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
            // 因为涉及到实参或形参optional，所以需要返回null指示
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
            //  '[' ConstExp ']' optional
            if (getTokenType() == TokenType.LBRACK) {
                lbrack = token;
                nextToken();
                constExp = parseConstExp();
                if (constExp == null) {
                    return null;
                }
                if (getTokenType() == TokenType.RBRACK) {
                    rbrack = token;
                    nextToken();
                } else {
                    // error k
                    Error.errors.add(new Error(constExp.lineNo, ErrorType.k));

                    // fix error
                    rbrack = new Token("]", TokenType.RBRACK, -1, -1);
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
                throw new RuntimeException("encounter " + token.content + " but should be =");
            }

        } else {
            // error
            System.out.println("encounter " + token.content + " but should be indentifier");
            return null;
        }

    }

    private ConstInitVal parseConstInitVal() {
        // ConstInitVal -> ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        ConstExp constExp = null;
        List<ConstExp> constExps = null;
        List<Token> commas = null;
        Token lbrace = null;
        Token rbrace = null;
        Token stringConst = null;
        // ConstInitVal -> '{' [ ConstExp { ',' ConstExp } ] '}'
        if (getTokenType() == TokenType.LBRACE) {
            lbrace = token;
            nextToken();
            if (getTokenType() != TokenType.RBRACE) {
                constExp = parseConstExp();
                if (constExp == null) {
                    return null;
                }
                constExps = new ArrayList<>();
                constExps.add(constExp);
                while (getTokenType() == TokenType.COMMA) {
                    if (commas == null) {
                        commas = new ArrayList<>();
                    }
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
            constExp = parseConstExp();
            return new ConstInitVal(constExp);
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

        // 本实现为右递归
        MulExp mulExp = null;
        Token op = null;
        AddExp addExp = null;

        mulExp = parseMulExp();
        if (mulExp == null) {
            return null;
        }
        if (getTokenType() == TokenType.PLUS
                || getTokenType() == TokenType.MINU) {
            op = token;
            nextToken();
            addExp = parseAddExp();
        }
        return new AddExp(mulExp, addExp, op);
    }

    private MulExp parseMulExp() {
        // MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        // MulExp -> UnaryExp | UnaryExp ('*' | '/' | '%') MulExp  // 右递归
        UnaryExp unaryExp = null;
        Token op = null;
        MulExp mulExp = null;

        unaryExp = parseUnaryExp();
        if (unaryExp == null) {
            return null;
        }
        if (getTokenType() == TokenType.MULT
                || getTokenType() == TokenType.DIV
                || getTokenType() == TokenType.MOD) {
            op = token;
            nextToken();
            mulExp = parseMulExp();
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
        if (getTokenType() == TokenType.IDENFR && getPreReadTokenType(1) == TokenType.LPARENT) {
            ident = token;
            nextToken();
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
            } else {
                // error j
                Error error = new Error();
                if (funcRParams != null) {
                    error.lineNo = funcRParams.lineNo;
                } else {
                    error.lineNo = lparent.lineNo;
                }
                error.type = ErrorType.j;
                Error.errors.add(error);

                rparent = new Token(")", TokenType.RPARENT, -1, -1);
            }

            return new UnaryExp(ident, lparent, rparent, funcRParams);
        }
        // UnaryExp -> UnaryOp UnaryExp
        else if (getTokenType() == TokenType.PLUS
                || getTokenType() == TokenType.MINU
                || getTokenType() == TokenType.NOT) {
            // UnaryExp -> UnaryOp UnaryExp
            unaryOp = parseUnaryOp();
            unaryExp = parseUnaryExp();
            // 对于右递归，如果有符号，那么递归项就不该是null
            if (unaryExp == null) {
                return null;
            }
            return new UnaryExp(unaryOp, unaryExp);
        } else { // UnaryExp -> PrimaryExp
            primaryExp = parsePrimaryExp();
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
            if (exp == null) {
                return null;
            }
            if (getTokenType() == TokenType.RPARENT) {
                rparent = token;
                nextToken();
            } else {
                // error j
                Error.errors.add(new Error(exp.lineNo, ErrorType.j));
                rparent = new Token(")", TokenType.RPARENT, -1, -1);
            }
            return new PrimaryExp(lparent, rparent, exp);
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
            // '[' Exp ']' optional
            if (getTokenType() == TokenType.LBRACK) {
                lbrack = token;
                nextToken();
                exp = parseExp();
                if (exp == null) {
                    return null;
                }
                if (getTokenType() == TokenType.RBRACK) {
                    rbrack = token;
                    nextToken();
                } else {
                    // error k
                    if (!Error.isExist(exp.lineNo, ErrorType.k)) {
                        Error.errors.add(new Error(exp.lineNo, ErrorType.k));
                    }
                    // fix it
                    rbrack = new Token("]", TokenType.RBRACK, -1, -1);
                }
            }
            return new LVal(ident, lbrack, exp, rbrack);
        } else {
            // 不匹配
            // 因为try用到了这个parse，所以要及时返回null
            return null;
        }
    }

    private Number parseNumber() {
        Token intConst = null;
        if (getTokenType() == TokenType.INTCON) {
            intConst = token;
            nextToken();
            return new Number(intConst);
        } else {
            // error
            return null;
        }

    }

}
