package frontend.Parser;

import frontend.Lexer.Token;
import frontend.Lexer.TokenType;
import frontend.Parser.Declaration.*;
import frontend.Parser.Declaration.ConstInitValElements.ConstExpArray;
import frontend.Parser.Declaration.InitValElements.ExpArray;
import frontend.Parser.Expression.*;
import frontend.Parser.Expression.PrimaryExpElements.*;
import frontend.Parser.Expression.PrimaryExpElements.Character;
import frontend.Parser.Expression.PrimaryExpElements.Number;
import frontend.Parser.Expression.UnaryExpElements.UnaryOpExp;
import frontend.Parser.Function.*;
import frontend.Parser.Statement.*;
import frontend.Parser.Statement.StmtElements.*;
import frontend.Parser.Terminators.BType;
import frontend.Parser.Terminators.CharConst;
import frontend.Parser.Terminators.IntConst;
import frontend.Parser.Terminators.StringConst;

import java.util.ArrayList;
import java.util.List;

public class Parser {
    private List<Token> tokens;
    private int curPos;      // 当前字符串位置指针
    private List<Token> errorTokens;

    
    public Parser(List<Token> tokens) {
        this.tokens = tokens;
        this.curPos = 0;
        this.errorTokens = new ArrayList<>();
    }

    // CompUnit -> {Decl} {FuncDef} MainFuncDef
    public CompUnit parseCompUnit() {
        ArrayList<Decl> decls = parseDecls();
        ArrayList<FuncDef> funcDefs = parseFuncDefs();
        MainFuncDef mainFuncDef = parseMainFuncDef();
        return new CompUnit(decls, funcDefs, mainFuncDef);
    }

    public ArrayList<FuncDef> parseFuncDefs() {
        ArrayList<FuncDef> funcDefs = new ArrayList<>();

        while (curPos < tokens.size()) {
            Token secondToken = tokens.get(curPos + 1);
            if (secondToken.getType() == TokenType.MAINTK) {
                return funcDefs;
            }
            funcDefs.add(parseFuncDef());
        }
        return funcDefs;
    }

    public Block parseBlock() {
        Token lbraceToken = tokens.get(curPos);
        curPos++;

        ArrayList<BlockItem> blockItems = new ArrayList<>();
        while (tokens.get(curPos).getType() != TokenType.RBRACE) {
            BlockItem blockItem = parseBlockItem();
            blockItems.add(blockItem);
        }

        Token rbraceToken = tokens.get(curPos);
        curPos++;

        return new Block(lbraceToken, blockItems, rbraceToken);
    }

    // BlockItem -> Decl | Stmt
    public BlockItem parseBlockItem() {
        BlockItem blockItem;
        Token curToken = tokens.get(curPos);
        if (curToken.getType() == TokenType.CONSTTK ||
                curToken.getType() == TokenType.INTTK ||
                curToken.getType() == TokenType.CHARTK) {
            Decl decl = parseDecl();
            blockItem = new BlockItem(decl);
        } else {
            Stmt stmt = parseStmt();
            blockItem = new BlockItem(stmt);
        }
        return blockItem;
    }

    private Decl parseDecl() {
        Decl decl = null;
        Token firstToken = tokens.get(curPos);
        Token thirdToken = null;
        if (curPos + 2 < tokens.size()) {
            thirdToken = tokens.get(curPos + 2);
        }
        if (thirdToken != null && thirdToken.getType() == TokenType.LPARENT) {    // FuncDef MainFuncDef
            return decl;
        } else if (firstToken.getType() == TokenType.CONSTTK) {
            ConstDecl constDecl = parseConstDecl();
            decl = new Decl(constDecl);
        } else {
            VarDecl varDecl = parseVarDecl();
            decl = new Decl(varDecl);
        }
        return decl;
    }

    public Stmt parseStmt() {
        StmtEle stmt;
        Token curToken = tokens.get(curPos);
        Token secondToken = tokens.get(curPos + 1);
        Token thirdToken = tokens.get(curPos + 2);
        if (curToken.getType() == TokenType.IFTK) {
            stmt = parseIfStmtEle();
        }
        else if (curToken.getType() == TokenType.FORTK) {
            stmt = parseForStmtEle();
        }
        else if (curToken.getType() == TokenType.BREAKTK) {
            stmt = parseBreakStmtEle();
        }
        else if (curToken.getType() == TokenType.CONTINUETK) {
            stmt = parseContinueStmtEle();
        }
        else if (curToken.getType() == TokenType.RETURNTK) {
            stmt = parseReturnStmtEle();
        }
        else if (curToken.getType() == TokenType.PRINTFTK) {
            stmt = parsePrintfStmtEle();
        }
        else if (secondToken.getType() == TokenType.ASSIGN) {
            if (thirdToken.getType() == TokenType.GETINTTK) {
                stmt = parseGetintStmtEle();
            } else if (thirdToken.getType() == TokenType.GETCHARTK) {
                stmt = parseGetcharStmtEle();
            } else {
                stmt = parseLvalExpStmtEle();
            }
        }
        else if (curToken.getType() == TokenType.LBRACE) {
            stmt = parseBlock();
        }
        else {
            stmt = parseExpStmtEle();
        }
        return new Stmt(stmt);
    }

    public StmtEle parseExpStmtEle() {
        Exp exp = null;
        Token curToken = tokens.get(curPos);
        if (curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                curToken.getType() == TokenType.NOT || curToken.getType() == TokenType.IDENFR ||
                curToken.getType() == TokenType.LPARENT ||
                curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHRCON) {
            exp = parseExp();
        }

        Token semicolonToken;
        if (tokens.get(curPos).getType() == TokenType.SEMICN) {
            semicolonToken = tokens.get(curPos);
            curPos++;
        } else {
            semicolonToken = new Token(TokenType.i, ";", tokens.get(curPos - 1).getLineno());
        }
        return new ExpStmtEle(exp, semicolonToken);
    }

    public StmtEle parseLvalExpStmtEle() {
        LVal lVal = parseLVal();
        Token assignToken = tokens.get(curPos);
        curPos++;
        Exp exp = parseExp();
        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);
        return new LvalExpStmtEle(lVal, assignToken, exp, semicolonToken);
    }

    public GetcharStmtEle parseGetcharStmtEle() {
        LVal lVal = parseLVal();
        Token assignToken = tokens.get(curPos);
        curPos++;
        Token getcharToken = tokens.get(curPos);
        curPos++;
        Token lparentToken = tokens.get(curPos);
        curPos++;

        Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);
        return new GetcharStmtEle(
                lVal, assignToken, getcharToken, lparentToken, rparentToken, semicolonToken);
    }

    public GetintStmtEle parseGetintStmtEle() {
        LVal lVal = parseLVal();
        Token assignToken = tokens.get(curPos);
        curPos++;
        Token getintToken = tokens.get(curPos);
        curPos++;
        Token lparentToken = tokens.get(curPos);
        curPos++;

        Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);
        return new GetintStmtEle(
                lVal, assignToken, getintToken, lparentToken, rparentToken, semicolonToken);
    }

    public PrintfStmtEle parsePrintfStmtEle() {
        Token printfToken = tokens.get(curPos);
        curPos++;
        Token lparentToken = tokens.get(curPos);
        curPos++;
        StringConst stringConst = parseStringConst();

        ArrayList<Token> commaTokens = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (tokens.get(curPos).getType() == TokenType.COMMA) {
            commaTokens.add(tokens.get(curPos));
            curPos++;
            exps.add(parseExp());
        }

        Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);
        return new PrintfStmtEle(
                printfToken, lparentToken, stringConst, commaTokens, exps, rparentToken,
                        semicolonToken);
    }

    public ReturnStmtEle parseReturnStmtEle() {
        Token returnToken = tokens.get(curPos);
        curPos++;

        Token curToken = tokens.get(curPos);
        Exp exp = null;
        if (curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                curToken.getType() == TokenType.NOT || curToken.getType() == TokenType.IDENFR ||
                curToken.getType() == TokenType.LPARENT ||
                curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHRCON) {
            exp = parseExp();
        }

        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);
        return new ReturnStmtEle(returnToken, exp, semicolonToken);
    }

    public ContinueStmtEle parseContinueStmtEle() {
        Token continueToken = tokens.get(curPos);
        curPos++;
        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);
        return new ContinueStmtEle(continueToken, semicolonToken);
    }

    public BreakStmtEle parseBreakStmtEle() {
        Token breakToken = tokens.get(curPos);
        curPos++;
        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);
        return new BreakStmtEle(breakToken, semicolonToken);
    }

    public ForStmtEle parseForStmtEle() {
        Token forToken = tokens.get(curPos);
        curPos++;
        Token lparentToken = tokens.get(curPos);
        curPos++;

        ForStmt forStmt1 = null;
        if (tokens.get(curPos).getType() == TokenType.IDENFR) {
            forStmt1 = parseForStmt();
        }

        Token semicolonToken1 = getAndCheckError_ijk(TokenType.SEMICN);

        Cond cond = null;
        Token curToken = tokens.get(curPos);
        if (curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                curToken.getType() == TokenType.NOT || curToken.getType() == TokenType.IDENFR ||
                curToken.getType() == TokenType.LPARENT ||
                curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHRCON) {
            cond = parseCond();
        }

        Token semicolonToken2 = getAndCheckError_ijk(TokenType.SEMICN);

        ForStmt forStmt2 = null;
        if (tokens.get(curPos).getType() == TokenType.IDENFR) {
            forStmt2 = parseForStmt();
        }

        Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
        Stmt stmt = parseStmt();
        return new ForStmtEle(
                forToken, lparentToken, forStmt1, semicolonToken1, cond, semicolonToken2, forStmt2, rparentToken, stmt);
    }

    public Cond parseCond() {
        LOrExp lOrExp = parseLOrExp();
        return new Cond(lOrExp);
    }

    public LOrExp parseLOrExp() {
        LAndExp firstLAndExp = parseLAndExp();
        ArrayList<Token> orTokens = new ArrayList<>();
        ArrayList<LAndExp> lAndExps = new ArrayList<>();
        while (tokens.get(curPos).getType() == TokenType.OR) {
            orTokens.add(tokens.get(curPos));
            curPos++;
            lAndExps.add(parseLAndExp());
        }
        return new LOrExp(firstLAndExp, orTokens, lAndExps);
    }

    public LAndExp parseLAndExp() {
        EqExp firstEqExp = parseEqExp();
        ArrayList<Token> andTokens = new ArrayList<>();
        ArrayList<EqExp> eqExps = new ArrayList<>();
        while (tokens.get(curPos).getType() == TokenType.AND) {
            andTokens.add(tokens.get(curPos));
            curPos++;
            eqExps.add(parseEqExp());
        }
        return new LAndExp(firstEqExp, andTokens, eqExps);
    }

    public EqExp parseEqExp() {
        RelExp firstRelExp = parseRelExp();
        ArrayList<Token> eqTokens = new ArrayList<>();
        ArrayList<RelExp> relExps = new ArrayList<>();
        while (tokens.get(curPos).getType() == TokenType.EQL ||
                tokens.get(curPos).getType() == TokenType.NEQ) {
            eqTokens.add(tokens.get(curPos));
            curPos++;
            relExps.add(parseRelExp());
        }
        return new EqExp(firstRelExp, eqTokens, relExps);
    }

    public RelExp parseRelExp() {
        AddExp firstAddExp = parseAddExp();
        ArrayList<Token> relTokens = new ArrayList<>();
        ArrayList<AddExp> addExps = new ArrayList<>();
        while (tokens.get(curPos).getType() == TokenType.LSS ||
                tokens.get(curPos).getType() == TokenType.LEQ ||
                tokens.get(curPos).getType() == TokenType.GRE ||
                tokens.get(curPos).getType() == TokenType.GEQ) {
            relTokens.add(tokens.get(curPos));
            curPos++;
            addExps.add(parseAddExp());
        }
        return new RelExp(firstAddExp, relTokens, addExps);
    }

    public ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        Token assignToken = tokens.get(curPos);
        curPos++;
        Exp exp = parseExp();
        return new ForStmt(lVal, assignToken, exp);
    }

    public StmtEle parseIfStmtEle() {
        Token ifToken = tokens.get(curPos);
        curPos++;
        Token lparentToken = tokens.get(curPos);
        curPos++;
        Cond cond = parseCond();
        Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
        Stmt trueStmt = parseStmt();

        Token elseToken = null;
        Stmt falseStmt = null;
        if (tokens.get(curPos).getType() == TokenType.ELSETK) {
            elseToken = tokens.get(curPos);
            curPos++;
            falseStmt = parseStmt();
        }
        return new IfStmtEle(ifToken, lparentToken, cond, rparentToken, trueStmt, elseToken, falseStmt);
    }

    public FuncFParam parseFuncFParam() {
        BType bType = parseBType();
        Ident ident = parseIdent();

        Token lbrackToken = null;
        Token rbrackToken = null;
        if (tokens.get(curPos).getType() == TokenType.LBRACK) {
            lbrackToken = tokens.get(curPos);
            curPos++;
            rbrackToken = getAndCheckError_ijk(TokenType.RBRACK);
        }
        return new FuncFParam(bType, ident, lbrackToken, rbrackToken);
    }

    public FuncType parseFuncType() {
        FuncType funcType = null;
        Token curToken = tokens.get(curPos);
        if (curToken.getType() == TokenType.INTTK ||
                curToken.getType() == TokenType.CHARTK ||
                curToken.getType() == TokenType.VOIDTK) {
            funcType = new FuncType(curToken);
            curPos++;
        } else {
            System.err.println("parseFuncType Error");
        }
        return funcType;
    }

    // Decl -> ConstDecl | VarDecl
    // ConstDecl -> 'const' BType ConstDef {',' ConstDef} ';'
    // VarDecl -> BType VarDef {',' VarDef} ';'
    public ArrayList<Decl> parseDecls() {
        ArrayList<Decl> decls = new ArrayList<>();

        while (curPos < tokens.size()) {
            Token firstToken = tokens.get(curPos);
            Token thirdToken = null;
            if (curPos + 2 < tokens.size()) {
                thirdToken = tokens.get(curPos + 2);
            }
            if ( thirdToken != null && thirdToken.getType() == TokenType.LPARENT) {    // FuncDef MainFuncDef
                return decls;
            } else if (firstToken.getType() == TokenType.CONSTTK) {
                ConstDecl constDecl = parseConstDecl();
                decls.add(new Decl(constDecl));
            } else {
                VarDecl varDecl = parseVarDecl();
                decls.add(new Decl(varDecl));
            }
        }
        return decls;
    }

    public ConstDecl parseConstDecl() {
        assert tokens.get(curPos).getType() == TokenType.CONSTTK;
        Token constToken = tokens.get(curPos);
        curPos++;
        BType bType = parseBType();
        ConstDef constDef = parseConstDef();

        ArrayList<Token> commaTokens = new ArrayList<>();
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        while (tokens.get(curPos).getType() == TokenType.COMMA) {
            commaTokens.add(tokens.get(curPos));
            curPos++;
            constDefs.add(parseConstDef());
        }

        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);

        return new ConstDecl(constToken, bType, constDef, commaTokens, constDefs, semicolonToken);
    }

    public ConstDef parseConstDef() {
        Ident ident = parseIdent();

        Token lbrackToken = null;
        ConstExp constExp = null;
        Token rbrackToken = null;
        if (tokens.get(curPos).getType() == TokenType.LBRACK) {
            lbrackToken = tokens.get(curPos);
            curPos++;
            constExp = parseConstExp();
            rbrackToken = getAndCheckError_ijk(TokenType.RBRACK);
        }
        assert tokens.get(curPos).getType() == TokenType.ASSIGN;
        Token assignToken = tokens.get(curPos);
        curPos++;
        ConstInitVal constInitVal = parseConstInitVal();
        return new ConstDef(ident, lbrackToken, constExp, rbrackToken, assignToken, constInitVal);
    }

    public ConstInitVal parseConstInitVal() {
        // '{' [ConstExp {',' ConstExp}] '}'
        if (tokens.get(curPos).getType() == TokenType.LBRACE) {
            Token lbraceToken = tokens.get(curPos);
            curPos++;

            ConstExp firstConstExp = null;
            ArrayList<Token> commaTokens = new ArrayList<>();
            ArrayList<ConstExp> constExps = new ArrayList<>();

            if (tokens.get(curPos).getType() != TokenType.RBRACE) {
                firstConstExp = parseConstExp();
                while (tokens.get(curPos).getType() == TokenType.COMMA) {
                    commaTokens.add(tokens.get(curPos));
                    curPos++;
                    constExps.add(parseConstExp());
                }
            }
            assert tokens.get(curPos).getType() == TokenType.RBRACE;
            Token rbraceToken = tokens.get(curPos);
            curPos++;
            ConstExpArray constExpArray = new ConstExpArray(lbraceToken, firstConstExp, commaTokens, constExps, rbraceToken);
            return new ConstInitVal(constExpArray);
        }
        // StringConst
        else if (tokens.get(curPos).getType() == TokenType.STRCON) {
            StringConst stringConst = parseStringConst();
            return new ConstInitVal(stringConst);
        }
        // ConstExp
        else {
            ConstExp constExp = parseConstExp();
            return new ConstInitVal(constExp);
        }
    }

    public Exp parseExp() {
        AddExp addExp = parseAddExp();
        return new Exp(addExp);
    }

    public ConstExp parseConstExp() {
        AddExp addExp = parseAddExp();
        return new ConstExp(addExp);
    }

    public AddExp parseAddExp() {
        MulExp mulExp = parseMulExp();

        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<MulExp> mulExps = new ArrayList<>();
        
        Token curToken = tokens.get(curPos);
        while (curToken.getType() == TokenType.PLUS ||
                curToken.getType() == TokenType.MINU) {
            operators.add(curToken);
            curPos++;
            mulExps.add(parseMulExp());
        }
        return new AddExp(mulExp, operators, mulExps);
    }

    public MulExp parseMulExp() {
        UnaryExp unaryExp = parseUnaryExp();

        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        
        Token curToken = tokens.get(curPos);
        while (curToken.getType() == TokenType.MULT ||
                curToken.getType() == TokenType.DIV ||
                curToken.getType() == TokenType.MOD) {
            operators.add(curToken);
            curPos++;
            unaryExps.add(parseUnaryExp());
        }
        return new MulExp(unaryExp, operators, unaryExps);
    }

    public UnaryExp parseUnaryExp() {
        Token curToken = tokens.get(curPos);
        // Ident '(' [FuncRParams] ')'
        // FuncRParams -> Exp {',' Exp}
        if (curToken.getType() == TokenType.IDENFR &&
                tokens.get(curPos + 1).getType() == TokenType.LPARENT) {
            Ident ident = parseIdent();
            Token lparentToken = curToken;
            curPos++;

            Exp firstFuncRParam = null;
            ArrayList<Token> commaTokens = new ArrayList<>();
            ArrayList<Exp> funcRParams = new ArrayList<>();
            curToken = tokens.get(curPos);
            if (curToken.getType() == TokenType.PLUS || curToken.getType() == TokenType.MINU ||
                    curToken.getType() == TokenType.NOT || curToken.getType() == TokenType.IDENFR ||
                    curToken.getType() == TokenType.LPARENT ||
                    curToken.getType() == TokenType.INTCON || curToken.getType() == TokenType.CHRCON) {
                firstFuncRParam = parseExp();
                while (tokens.get(curPos).getType() == TokenType.COMMA) {
                    commaTokens.add(tokens.get(curPos));
                    curPos++;
                    funcRParams.add(parseExp());
                }
            }

            Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
            FuncCallExp funcCallExp = new FuncCallExp(ident, lparentToken, firstFuncRParam, commaTokens, funcRParams, rparentToken);
            return new UnaryExp(funcCallExp);
        }
        // UnaryOp UnaryExp
        // UnaryOp -> '+' | '-' | '!'
        else if (curToken.getType() == TokenType.PLUS ||
                curToken.getType() == TokenType.MINU ||
                curToken.getType() == TokenType.NOT) {
            UnaryOp unaryOp = parseUnaryOp();
            UnaryExp unaryExp = parseUnaryExp();
            UnaryOpExp unaryOpExp = new UnaryOpExp(unaryOp, unaryExp);
            return new UnaryExp(unaryOpExp);
        }
        // PrimaryExp
        else {
            PrimaryExp primaryExp = parsePrimaryExp();
            return new UnaryExp(primaryExp);
        }
    }

    public PrimaryExp parsePrimaryExp() {
        // '(' Exp ')'
        if (tokens.get(curPos).getType() == TokenType.LPARENT) {
            Token lparentToken = tokens.get(curPos);
            curPos++;
            Exp exp = parseExp();
            Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
            Exp_parent expParent = new Exp_parent(lparentToken, exp, rparentToken);
            return new PrimaryExp(expParent);
        }
        // LVal
        else if (tokens.get(curPos).getType() == TokenType.IDENFR) {
            LVal lVal = parseLVal();
            return new PrimaryExp(lVal);
        }
        // Number
        else if (tokens.get(curPos).getType() == TokenType.INTCON) {
            IntConst intConst = parseIntConst();
            Number number = new Number(intConst);
            return new PrimaryExp(number);
        }
        // Character
        else if (tokens.get(curPos).getType() == TokenType.CHRCON) {
            CharConst charConst = parseCharConst();
            curPos++;
            Character character = new Character(charConst);
            return new PrimaryExp(character);
        }
        else {
            System.err.println("parsePrimaryExp Error");
            return null;
        }
    }

    public LVal parseLVal() {
        Ident ident = parseIdent();

        Token lbrackToken = null;
        Exp exp = null;
        Token rbrackToken = null;
        if (tokens.get(curPos).getType() == TokenType.LBRACK) {
            lbrackToken = tokens.get(curPos);
            curPos++;
            exp = parseExp();
            rbrackToken = getAndCheckError_ijk(TokenType.RBRACK);
        }
        return new LVal(ident, lbrackToken, exp, rbrackToken);
    }

    public VarDecl parseVarDecl() {
        BType bType = parseBType();
        VarDef firstvarDef = parseVarDef();

        ArrayList<Token> commaTokens = new ArrayList<>();
        ArrayList<VarDef> varDefs = new ArrayList<>();
        while (tokens.get(curPos).getType() == TokenType.COMMA) {
            commaTokens.add(tokens.get(curPos));
            curPos++;
            varDefs.add(parseVarDef());
        }

        Token semicolonToken = getAndCheckError_ijk(TokenType.SEMICN);
        return new VarDecl(bType, firstvarDef, commaTokens, varDefs, semicolonToken);
    }

    public VarDef parseVarDef() {
        Ident ident = parseIdent();

        Token lbrackToken = null;
        ConstExp constExp = null;
        Token rbrackToken = null;
        if (tokens.get(curPos).getType() == TokenType.LBRACK) {
            lbrackToken = tokens.get(curPos);
            curPos++;
            constExp = parseConstExp();
            rbrackToken = getAndCheckError_ijk(TokenType.RBRACK);
        }

        Token assignToken = null;
        InitVal initVal = null;
        if (tokens.get(curPos).getType() == TokenType.ASSIGN) {
            assignToken = tokens.get(curPos);
            curPos++;
            initVal = parseInitVal();
        }
        return new VarDef(ident, lbrackToken, constExp, rbrackToken, assignToken, initVal);
    }

    public InitVal parseInitVal() {
        // '{' [Exp {',' Exp}] '}'
        if (tokens.get(curPos).getType() == TokenType.LBRACE) {
            Token lbraceToken = tokens.get(curPos);
            curPos++;

            Exp firstExp = null;
            ArrayList<Token> commaTokens = new ArrayList<>();
            ArrayList<Exp> exps = new ArrayList<>();

            if (tokens.get(curPos).getType() != TokenType.RBRACE) {
                firstExp = parseExp();
                while (tokens.get(curPos).getType() == TokenType.COMMA) {
                    commaTokens.add(tokens.get(curPos));
                    curPos++;
                    exps.add(parseExp());
                }
            }
            assert tokens.get(curPos).getType() == TokenType.RBRACE;
            Token rbraceToken = tokens.get(curPos);
            curPos++;
            ExpArray expArray = new ExpArray(lbraceToken, firstExp, commaTokens, exps, rbraceToken);
            return new InitVal(expArray);
        }
        // StringConst
        else if (tokens.get(curPos).getType() == TokenType.STRCON) {
            StringConst stringConst = parseStringConst();
            return new InitVal(stringConst);
        }
        // Exp
        else {
            Exp exp = parseExp();
            return new InitVal(exp);
        }
    }

    // FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
    public FuncDef parseFuncDef() {
        FuncType funcType = parseFuncType();
        Ident ident = parseIdent();
        Token lparentToken = tokens.get(curPos);
        curPos++;

        FuncFParam firstFuncFParam = null;
        ArrayList<Token> commaTokens = new ArrayList<>();
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        if (tokens.get(curPos).getType() == TokenType.INTTK
            || tokens.get(curPos).getType() == TokenType.CHARTK) {
            firstFuncFParam = parseFuncFParam();
            while (tokens.get(curPos).getType() == TokenType.COMMA) {
                commaTokens.add(tokens.get(curPos));
                curPos++;
                funcFParams.add(parseFuncFParam());
            }
        }
        Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
        Block block = parseBlock();
        return new FuncDef(funcType, ident, lparentToken, firstFuncFParam, commaTokens, funcFParams, rparentToken, block);
    }

    // MainFuncDef -> 'int' 'main' '(' ')' Block
    public MainFuncDef parseMainFuncDef() {
        if (curPos < tokens.size()) {
            Token intToken = tokens.get(curPos);
            curPos++;
            Token mainToken = tokens.get(curPos);
            curPos++;
            Token lparentToken = tokens.get(curPos);
            curPos++;
            Token rparentToken = getAndCheckError_ijk(TokenType.RPARENT);
            Block block = parseBlock();
            return new MainFuncDef(intToken, mainToken, lparentToken, rparentToken, block);
        } else {
            return null;
        }

    }

    public UnaryOp parseUnaryOp() {
        UnaryOp unaryOp = null;
        Token curToken = tokens.get(curPos);
        if (curToken.getType() == TokenType.PLUS ||
                curToken.getType() == TokenType.MINU ||
                curToken.getType() == TokenType.NOT) {
            unaryOp = new UnaryOp(curToken);
            curPos++;
        } else {
            System.err.println("parseUnaryOp Error");
        }
        return unaryOp;
    }

    public CharConst parseCharConst() {
        CharConst charConst = null;
        if (tokens.get(curPos).getType() == TokenType.CHRCON) {
            charConst = new CharConst(tokens.get(curPos));
            curPos++;
        } else {
            System.err.println("parseCharConst Error");
        }
        return charConst;
    }

    public Ident parseIdent() {
        Ident ident = null;
        if (tokens.get(curPos).getType() == TokenType.IDENFR) {
            ident = new Ident(tokens.get(curPos));
            curPos++;
        } else {
            System.err.println("parseIdent Error");
        }
        return ident;
    }

    public IntConst parseIntConst() {
        IntConst intConst = null;
        if (tokens.get(curPos).getType() == TokenType.INTCON) {
            intConst = new IntConst(tokens.get(curPos));
            curPos++;
        } else {
            System.err.println("parseIntConst Error");
        }
        return intConst;
    }

    public StringConst parseStringConst() {
        StringConst stringConst = null;
        if (tokens.get(curPos).getType() == TokenType.STRCON) {
            stringConst = new StringConst(tokens.get(curPos));
            curPos++;
        } else {
            System.err.println("parseStringConst Error");
        }
        return stringConst;
    }

    public BType parseBType() {
        BType bType = null;
        Token curToken = tokens.get(curPos);
        if (curToken.getType() == TokenType.INTTK ||
                curToken.getType() == TokenType.CHARTK) {
            bType = new BType(curToken);
            curPos++;
        } else {
            System.err.println("parseBType Error");
        }
        return bType;
    }

    public Token getAndCheckError_ijk(TokenType tokenType) {
        Token token = null;
        Token errorToken = null;
        if (tokens.get(curPos).getType() == tokenType) {
            token = tokens.get(curPos);
            curPos++;
        } else {
            switch (tokenType) {
                case SEMICN:
                    errorToken = new Token(TokenType.i, ";", tokens.get(curPos - 1).getLineno());
                    break;
                case RPARENT:
                    errorToken = new Token(TokenType.j, ")", tokens.get(curPos - 1).getLineno());
                    break;
                case RBRACK:
                    errorToken = new Token(TokenType.k, "]", tokens.get(curPos - 1).getLineno());
                    break;
                default:
                    System.err.println("checkError Error");
            }
            errorTokens.add(errorToken);
        }
        return token;
    }

    public List<Token> getErrorTokens() {
        return errorTokens;
    }
}