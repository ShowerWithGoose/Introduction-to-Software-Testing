package frontend;

import error.Error;
import node.Character;
import node.Number;
import node.*;

import java.util.ArrayList;
import java.util.HashMap;

public class Parser {
    private HashMap<Integer, ArrayList<Token>> lexerTokens;
    private int curLineNum;
    private int curTokenIndex;
    // private Token curToken;
    private ArrayList<Object> syntaxList;
    private ArrayList<Error> errorList;

    public Parser(HashMap<Integer, ArrayList<Token>> lexerTokens) {
        this.lexerTokens = lexerTokens;
        int lineNum = 1;
        while (lexerTokens.containsKey(lineNum)
                && lexerTokens.get(lineNum).isEmpty()) {
            lineNum++;
        }
        curLineNum = lineNum;
        curTokenIndex = 0;
        syntaxList = new ArrayList<>();
        errorList = new ArrayList<>();
    }

    public void addSyntax(SyntaxType type) {
        syntaxList.add(type);
    }

    public void addToken(Token token) {
        syntaxList.add(token);
    }

    public ArrayList<Object> getSyntaxList() {
        return syntaxList;
    }

    public ArrayList<Error> getErrorList() {
        return errorList;
    }

    public void next() {
        if (!lexerTokens.containsKey(curLineNum)) return;
        addToken(peek());
        if (curTokenIndex + 1 < lexerTokens.get(curLineNum).size()) {
            curTokenIndex++;
            return;
        }
        ++curLineNum;
        while (lexerTokens.containsKey(curLineNum)
                && lexerTokens.get(curLineNum).isEmpty()) {
            curLineNum++;
        }
        curTokenIndex = 0;
    }

    public void nextButNotAdd() {
        if (!lexerTokens.containsKey(curLineNum)) return;
        if (curTokenIndex + 1 < lexerTokens.get(curLineNum).size()) {
            curTokenIndex++;
            return;
        }
        ++curLineNum;
        while (lexerTokens.containsKey(curLineNum)
                && lexerTokens.get(curLineNum).isEmpty()) {
            curLineNum++;
        }
        curTokenIndex = 0;
    }

    public Token lookAhead(int n) {
        int lineNum = curLineNum, tokenIndex = curTokenIndex;
        for (int i = 0; i < n; i++) { nextButNotAdd(); }
        Token token = peek();
        if (!lexerTokens.containsKey(curLineNum)) return null;
        curLineNum = lineNum;
        curTokenIndex = tokenIndex;
        return token;
    }

    public Token peek() {
        if (lexerTokens.containsKey(curLineNum)
                && curTokenIndex < lexerTokens.get(curLineNum).size()) {
            return lexerTokens.get(curLineNum).get(curTokenIndex);
        } else {
            return null;
        }
    }

    public int getPrevTokenLineNum() {
        if (curTokenIndex == 0) {
            int lineNum = curLineNum - 1;
            while (lexerTokens.containsKey(lineNum) && lexerTokens.get(lineNum).isEmpty()) {
                lineNum--;
            }
            return lineNum;
        } else {
            return curLineNum;
        }
    }

    public void restoreTokenIndex(int lineNum, int tokenIndex) {
        curLineNum = lineNum;
        curTokenIndex = tokenIndex;
    }

    public void restoreSyntaxList(int prevSize, int curSize) {
        syntaxList.subList(prevSize, curSize).clear();
    }

    public void restoreErrorList(int prevSize, int curSize) {
        errorList.subList(prevSize, curSize).clear();
    }

    public enum SyntaxType {
        CompUnit, Decl,
        ConstDecl, BType, ConstDef, ConstInitVal,
        VarDecl, VarDef, InitVal,
        FuncDef, MainFuncDef, FuncType, FuncFParams, FuncFParam,
        Block, BlockItem, Stmt, ForStmt,
        Exp, Cond, LVal, PrimaryExp,
        Number, Character,
        UnaryExp, UnaryOp,
        FuncRParams,
        MulExp, AddExp, RelExp, EqExp, LAndExp, LOrExp, ConstExp,
    }

    public CompUnit parseCompUnit() {
        ArrayList<Decl> declList = new ArrayList<>();
        while (true) {
            if (peek().getType() == Token.TokenType.INTTK
                    && lookAhead(1).getType() == Token.TokenType.MAINTK) break;

            if (isBType(peek())
                    && lookAhead(1).getType() == Token.TokenType.IDENFR
                    && lookAhead(2).getType() == Token.TokenType.LPARENT) {
                break;
            }

            Decl decl = parseDecl();
            if (decl == null) break;
            declList.add(decl);
        }

        ArrayList<FuncDef> funcDefList = new ArrayList<>();
        while (true) {
            if (peek().getType() == Token.TokenType.INTTK
                    && lookAhead(1).getType() == Token.TokenType.MAINTK) break;

            FuncDef funcDef = parseFuncDef();
            if (funcDef == null) break;
            funcDefList.add(funcDef);
        }

        MainFuncDef mainFuncDef = parseMainFuncDef();
        if (mainFuncDef == null) return null;

        addSyntax(SyntaxType.CompUnit);
        return new CompUnit(declList, funcDefList, mainFuncDef);
    }

    public Decl parseDecl() {
        ConstDecl constDecl = parseConstDecl();
        if (constDecl != null) {
            addSyntax(SyntaxType.Decl);
            return constDecl;
        }

        VarDecl varDecl = parseVarDecl();
        if (varDecl != null) {
            addSyntax(SyntaxType.Decl);
            return varDecl;
        }

        return null;
    }

    public ConstDecl parseConstDecl() {
        if (peek().getType() != Token.TokenType.CONSTTK) return null;
        next();

        BType bType = parseBType();
        if (bType == null) return null;

        ConstDef constDef = parseConstDef();
        if (constDef == null) return null;

        ArrayList<ConstDef> constDefList = new ArrayList<>();
        constDefList.add(constDef);
        while (peek().getType() == Token.TokenType.COMMA) {
            next();
            ConstDef constDef2 = parseConstDef();
            if (constDef2 == null) return null;
            constDefList.add(constDef2);
        }

        checkSEMICN();
        addSyntax(SyntaxType.ConstDecl);
        return new ConstDecl(bType, constDefList);
    }

    public BType parseBType() {
        if (!isBType(peek())) {
            return null;
        } else {
            Token.TokenType type = peek().getType();
            next();
            addSyntax(SyntaxType.BType);
            return new BType(type);
        }
    }

    public ConstDef parseConstDef() {
        if (peek().getType() != Token.TokenType.IDENFR) return null;
        Ident ident = new Ident(peek().getValue(), Ident.Type.CONST);
        next();

        ConstExp arraySize = null;
        if (peek().getType() == Token.TokenType.LBRACK) {
            next();
            arraySize = parseConstExp();
            if (arraySize == null) return null;
            checkRBRACK();
        }
        if (peek().getType() != Token.TokenType.ASSIGN) return null;
        next();

        ConstInitVal constInitVal = parseConstInitVal();
        if (constInitVal == null) return null;

        addSyntax(SyntaxType.ConstDef);
        return new ConstDef(ident, arraySize, constInitVal);
    }

    public ConstInitVal parseConstInitVal() {
        ConstExp constExp = parseConstExp();
        if (constExp != null) {
            addSyntax(SyntaxType.ConstInitVal);
            return new ConstInitVal(constExp);
        }

        if (peek().getType() == Token.TokenType.LBRACE) {
            ArrayList<ConstExp> initList = new ArrayList<>();
            next();
            ConstExp constExp2 = parseConstExp();
            if (constExp2 != null) {
                initList.add(constExp2);
                while (peek().getType() == Token.TokenType.COMMA) {
                    next();
                    ConstExp constExp3 = parseConstExp();
                    if (constExp3 == null) return null;
                    initList.add(constExp3);
                }
            }
            if (peek().getType() != Token.TokenType.RBRACE) return null;
            next();
            addSyntax(SyntaxType.ConstInitVal);
            return new ConstInitVal(initList);
        }

        if (peek().getType() == Token.TokenType.STRCON) {
            String stringConst = peek().getValue();
            next();
            addSyntax(SyntaxType.ConstInitVal);
            return new ConstInitVal(stringConst);
        }

        return null;
    }

    public VarDecl parseVarDecl() {
        BType bType = parseBType();
        if (bType == null) return null;

        VarDef varDef = parseVarDef();
        if (varDef == null) return null;

        ArrayList<VarDef> varDefList = new ArrayList<>();
        varDefList.add(varDef);
        while (peek().getType() == Token.TokenType.COMMA) {
            next();
            VarDef varDef2 = parseVarDef();
            if (varDef2 == null) return null;
            varDefList.add(varDef2);
        }

        checkSEMICN();
        addSyntax(SyntaxType.VarDecl);
        return new VarDecl(bType, varDefList);
    }

    public VarDef parseVarDef() {
        if (peek().getType() != Token.TokenType.IDENFR) return null;
        Ident ident = new Ident(peek().getValue(), Ident.Type.VAR);
        next();

        ConstExp arraySize = null;
        if (peek().getType() == Token.TokenType.LBRACK) {
            next();
            arraySize = parseConstExp();
            if (arraySize == null) return null;
            checkRBRACK();
        }

        InitVal initVal = null;
        if (peek().getType() == Token.TokenType.ASSIGN) {
            next();
            initVal = parseInitVal();
            if (initVal == null) return null;
        }

        addSyntax(SyntaxType.VarDef);
        return new VarDef(ident, arraySize, initVal);
    }

    public InitVal parseInitVal() {
        Exp exp = parseExp();
        if (exp != null) {
            addSyntax(SyntaxType.InitVal);
            return new InitVal(exp);
        }

        if (peek().getType() == Token.TokenType.LBRACE) {
            next();
            Exp exp2 = parseExp();
            ArrayList<Exp> initList = new ArrayList<>();
            if (exp2 != null) {
                initList.add(exp2);
                while (peek().getType() == Token.TokenType.COMMA) {
                    next();
                    Exp exp3 = parseExp();
                    if (exp3 == null) return null;
                    initList.add(exp3);
                }
            }
            if (peek().getType() != Token.TokenType.RBRACE) return null;
            next();
            addSyntax(SyntaxType.InitVal);
            return new InitVal(initList);
        }

        if (peek().getType() == Token.TokenType.STRCON) {
            String stringConst = peek().getValue();
            next();
            addSyntax(SyntaxType.InitVal);
            return new InitVal(stringConst);
        }

        return null;
    }

    public FuncDef parseFuncDef() {
        FuncType funcType = parseFuncType();
        if (funcType == null) return null;
        if (peek().getType() != Token.TokenType.IDENFR) return null;
        Ident ident = new Ident(peek().getValue(), Ident.Type.FUNC);
        next();
        if (peek().getType() != Token.TokenType.LPARENT) return null;
        next();
        FuncFParams funcFParams = parseFuncFParams();
        checkRPARENT();
        Block block = parseBlock();
        if (block == null) return null;
        addSyntax(SyntaxType.FuncDef);
        return new FuncDef(funcType, ident, funcFParams, block);
    }

    public FuncType parseFuncType() {
        if (isFuncType(peek())) {
            Token.TokenType type = peek().getType();
            next();
            addSyntax(SyntaxType.FuncType);
            return new FuncType(type);
        } else {
            return null;
        }
    }

    public FuncFParams parseFuncFParams() {
        FuncFParam funcFParam = parseFuncFParam();
        if (funcFParam == null) return null;
        ArrayList<FuncFParam> funcFParamList = new ArrayList<>();
        funcFParamList.add(funcFParam);
        while (peek().getType() == Token.TokenType.COMMA) {
            next();
            FuncFParam funcFParam2 = parseFuncFParam();
            if (funcFParam2 == null) return null;
            funcFParamList.add(funcFParam2);
        }
        addSyntax(SyntaxType.FuncFParams);
        return new FuncFParams(funcFParamList);
    }

    public FuncFParam parseFuncFParam() {
        BType bType = parseBType();
        if (bType == null) return null;
        if (peek().getType() != Token.TokenType.IDENFR) return null;
        Ident ident = new Ident(peek().getValue(), Ident.Type.VAR);
        next();
        boolean isArray = false;
        if (peek().getType() == Token.TokenType.LBRACK) {
            isArray = true;
            next();
            checkRBRACK();
        }
        addSyntax(SyntaxType.FuncFParam);
        return new FuncFParam(bType, ident, isArray);
    }

    public MainFuncDef parseMainFuncDef() {
        if (peek().getType() != Token.TokenType.INTTK) return null;
        next();
        if (peek().getType() != Token.TokenType.MAINTK) return null;
        next();
        if (peek().getType() != Token.TokenType.LPARENT) return null;
        next();
        checkRPARENT();
        Block block = parseBlock();
        if (block == null) return null;
        addSyntax(SyntaxType.MainFuncDef);
        return new MainFuncDef(block);
    }

    public Block parseBlock() {
        if (peek().getType() != Token.TokenType.LBRACE) return null;
        next();
        ArrayList<BlockItem> blockItemList = new ArrayList<>();
        while (true) {
            BlockItem blockItem = parseBlockItem();
            if (blockItem != null) {
                blockItemList.add(blockItem);
            } else {
                break;
            }
        }
        if (peek().getType() != Token.TokenType.RBRACE) return null;
        next();
        addSyntax(SyntaxType.Block);
        return new Block(blockItemList);
    }

    public BlockItem parseBlockItem() {
        Decl decl = parseDecl();
        if (decl != null) {
            addSyntax(SyntaxType.BlockItem);
            return new BlockItem(decl);
        }

        Stmt stmt = parseStmt();
        if (stmt != null) {
            addSyntax(SyntaxType.BlockItem);
            return new BlockItem(stmt);
        }

        return null;
    }

    public Stmt parseStmt() {
        // 检查并处理 SEMICN 分号直接结束的情况
        if (peek().getType() == Token.TokenType.SEMICN) {
            next();
            addSyntax(SyntaxType.Stmt);
            return new Stmt();
        }

        // 尝试解析 Block
        Block block = parseBlock();
        if (block != null) {
            addSyntax(SyntaxType.Stmt);
            return new Stmt(block);
        }

        // 尝试解析 If 语句
        if (peek().getType() == Token.TokenType.IFTK) {
            return handleIfStmt();
        }

        // 尝试解析 For 语句
        if (peek().getType() == Token.TokenType.FORTK) {
            return handleForStmt();
        }

        // 处理 Break 和 Continue 语句
        if (peek().getType() == Token.TokenType.BREAKTK || peek().getType() == Token.TokenType.CONTINUETK) {
            return handleBreakOrContinue();
        }

        // 处理 Return 语句
        if (peek().getType() == Token.TokenType.RETURNTK) {
            return handleReturnStmt();
        }

        // 处理 Printf 语句
        if (peek().getType() == Token.TokenType.PRINTFTK) {
            return handlePrintfStmt();
        }

        // 复杂处理 LVal '=' ... 与 [Exp];
        return handleComplexStmt();
    }

    public Stmt handleIfStmt() {
        next();
        if (peek().getType() != Token.TokenType.LPARENT) return null;
        next();
        Cond ifCond = parseCond();
        if (ifCond == null) return null;
        checkRPARENT();
        Stmt thenStmt = parseStmt();
        if (thenStmt == null) return null;
        Stmt elseStmt = null;
        if (peek().getType() == Token.TokenType.ELSETK) {
            next();
            elseStmt = parseStmt();
            if (elseStmt == null) return null;
        }
        addSyntax(SyntaxType.Stmt);
        return new MyIfStmt(ifCond, thenStmt, elseStmt);
    }

    public Stmt handleForStmt() {
        next();
        if (peek().getType() != Token.TokenType.LPARENT) return null;
        next();
        ForStmt forStmt1 = parseForStmt();
        if (peek().getType() != Token.TokenType.SEMICN) return null;
        next();
        Cond cond = parseCond();
        if (peek().getType() != Token.TokenType.SEMICN) return null;
        next();
        ForStmt forStmt2 = parseForStmt();
        if (peek().getType() != Token.TokenType.RPARENT) return null;
        next();
        Stmt stmt = parseStmt();
        if (stmt == null) return null;
        addSyntax(SyntaxType.Stmt);
        return new MyForStmt(forStmt1, cond, forStmt2, stmt);
    }

    public ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        if (lVal == null) return null;
        if (peek().getType() != Token.TokenType.ASSIGN) return null;
        next();
        Exp exp = parseExp();
        if (exp == null) return null;
        addSyntax(SyntaxType.ForStmt);
        return new ForStmt(lVal, exp);
    }

    private Stmt handleBreakOrContinue() {
        if (peek().getType() == Token.TokenType.BREAKTK) {
            next();
            checkSEMICN();
            addSyntax(SyntaxType.Stmt);
            return new MyBreakStmt();
        } else {
            next();
            checkSEMICN();
            addSyntax(SyntaxType.Stmt);
            return new MyContinueStmt();
        }
    }

    private Stmt handleReturnStmt() {
        next();
        Exp exp = parseExp();
        checkSEMICN();
        addSyntax(SyntaxType.Stmt);
        return new MyReturnStmt(exp);
    }

    private Stmt handlePrintfStmt() {
        next();
        if (peek().getType() != Token.TokenType.LPARENT) return null;
        next();
        if (peek().getType() != Token.TokenType.STRCON) return null;
        String stringConst = peek().getValue();
        next();
        ArrayList<Exp> expList = new ArrayList<>();
        while (peek().getType() == Token.TokenType.COMMA) {
            next();
            Exp exp = parseExp();
            if (exp == null) return null;
            expList.add(exp);
        }
        checkRPARENT();
        checkSEMICN();
        addSyntax(SyntaxType.Stmt);
        return new MyPrintfStmt(stringConst, expList);
    }

    private Stmt handleComplexStmt() {
        int prevLineNum = curLineNum, prevTokenIndex = curTokenIndex;
        int prevSyntaxListSize = syntaxList.size(), prevErrorListSize = errorList.size();

        LVal lVal = parseLVal();
        if (lVal != null) { // 超前扫描
            int curSyntaxListSize = syntaxList.size(), curErrorListSize = errorList.size();
            if (peek().getType() != Token.TokenType.ASSIGN) {
                restoreTokenIndex(prevLineNum, prevTokenIndex);
                restoreSyntaxList(prevSyntaxListSize, curSyntaxListSize);
                restoreErrorList(prevErrorListSize, curErrorListSize);
                // Exp;
                Exp exp = parseExp();
                checkSEMICN();
                addSyntax(SyntaxType.Stmt);
                return new Stmt(exp);
            } else { // LVal '='
                next();
                if (peek().getType() == Token.TokenType.GETINTTK) {
                    next();
                    if (peek().getType() != Token.TokenType.LPARENT) return null;
                    next();
                    checkRPARENT();
                    checkSEMICN();
                    addSyntax(SyntaxType.Stmt);
                    return new MyGetIntStmt(lVal);
                } else if (peek().getType() == Token.TokenType.GETCHARTK) {
                    next();
                    if (peek().getType() != Token.TokenType.LPARENT) return null;
                    next();
                    checkRPARENT();
                    checkSEMICN();
                    addSyntax(SyntaxType.Stmt);
                    return new MyGetCharStmt(lVal);
                } else {
                    Exp exp = parseExp();
                    if (exp == null) return null;
                    checkSEMICN();
                    addSyntax(SyntaxType.Stmt);
                    return new MyAssignStmt(lVal, exp);
                }
            }
        }

        Exp exp = parseExp();
        if (exp != null) { // Exp;
            checkSEMICN();
            addSyntax(SyntaxType.Stmt);
            return new Stmt(exp);
        }

        return null;
    }

    public Cond parseCond() {
        LOrExp lOrExp = parseLOrExp();
        if (lOrExp == null) return null;
        addSyntax(SyntaxType.Cond);
        return new Cond(lOrExp);
    }

    public Exp parseExp() {
        AddExp addExp = parseAddExp();
        if (addExp == null) return null;
        addSyntax(SyntaxType.Exp);
        return new Exp(addExp);
    }

    public AddExp parseAddExp() {
        MulExp mulExp = parseMulExp();
        if (mulExp == null) return null;
        AddExp addExp = new AddExp(mulExp);
        addSyntax(SyntaxType.AddExp);
        while (peek().getType() == Token.TokenType.PLUS
                || peek().getType() == Token.TokenType.MINU) {
            next();
            Token.TokenType op = peek().getType();
            MulExp mulExp2 = parseMulExp();
            if (mulExp2 == null) return null;
            addExp = new AddExp(addExp, op, mulExp2);
            addSyntax(SyntaxType.AddExp);
        }
        return addExp;
    }

    public MulExp parseMulExp() {
        UnaryExp unaryExp = parseUnaryExp();
        if (unaryExp == null) return null;
        MulExp mulExp = new MulExp(unaryExp);
        addSyntax(SyntaxType.MulExp);
        while (peek().getType() == Token.TokenType.MULT
                || peek().getType() == Token.TokenType.DIV
                || peek().getType() == Token.TokenType.MOD) {
            Token.TokenType op = peek().getType();
            next();
            UnaryExp unaryExp2 = parseUnaryExp();
            if (unaryExp2 == null) return null;
            mulExp = new MulExp(mulExp, op, unaryExp2);
            addSyntax(SyntaxType.MulExp);
        }
        return mulExp;
    }

    public UnaryExp parseUnaryExp() {
        if (peek().getType() == Token.TokenType.IDENFR
            && lookAhead(1).getType() == Token.TokenType.LPARENT) {
            Ident ident = new Ident(peek().getValue(), Ident.Type.FUNC);
            next();
            next();
            FuncRParams funcRParams = parseFuncRParams();
            checkRPARENT();
            addSyntax(SyntaxType.UnaryExp);
            return new UnaryExp(ident, funcRParams);
        }

        UnaryOp unaryOp = parseUnaryOp();
        if (unaryOp != null) {
            UnaryExp unaryExp = parseUnaryExp();
            if (unaryExp == null) return null;
            addSyntax(SyntaxType.UnaryExp);
            return new UnaryExp(unaryOp, unaryExp);
        }

        PrimaryExp primaryExp = parsePrimaryExp();
        if (primaryExp != null) {
            addSyntax(SyntaxType.UnaryExp);
            return new UnaryExp(primaryExp);
        }

        return null;
    }

    public FuncRParams parseFuncRParams() {
        ArrayList<Exp> expList = new ArrayList<>();
        Exp exp = parseExp();
        if (exp == null) return null;
        expList.add(exp);
        while (peek().getType() == Token.TokenType.COMMA) {
            next();
            Exp exp2 = parseExp();
            if (exp2 == null) return null;
            expList.add(exp2);
        }
        addSyntax(SyntaxType.FuncRParams);
        return new FuncRParams(expList);
    }

    public UnaryOp parseUnaryOp() {
        if (!isUnaryOp(peek())) return null;
        Token.TokenType op = peek().getType();
        next();
        addSyntax(SyntaxType.UnaryOp);
        return new UnaryOp(op);
    }

    public PrimaryExp parsePrimaryExp() {
        if (peek().getType() == Token.TokenType.LPARENT) {
            next();
            Exp exp = parseExp();
            if (exp == null) return null;
            checkRPARENT();
            addSyntax(SyntaxType.PrimaryExp);
            return new PrimaryExp(exp);
        }

        LVal lVal = parseLVal();
        if (lVal != null) {
            addSyntax(SyntaxType.PrimaryExp);
            return new PrimaryExp(lVal);
        }

        Number number = parseNumber();
        if (number != null) {
            addSyntax(SyntaxType.PrimaryExp);
            return new PrimaryExp(number);
        }

        Character character = parseCharacter();
        if (character != null) {
            addSyntax(SyntaxType.PrimaryExp);
            return new PrimaryExp(character);
        }

        return null;
    }

    public LOrExp parseLOrExp() {
        LAndExp landExp = parseLAndExp();
        if (landExp == null) return null;
        LOrExp lOrExp = new LOrExp(landExp);
        addSyntax(SyntaxType.LOrExp);
        while (peek().getType() == Token.TokenType.OR) {
            next();
            LAndExp landExp2 = parseLAndExp();
            if (landExp2 == null) return null;
            lOrExp = new LOrExp(lOrExp, landExp2);
            addSyntax(SyntaxType.LOrExp);
        }
        return lOrExp;
    }

    public LAndExp parseLAndExp() {
        EqExp eqExp = parseEqExp();
        if (eqExp == null) return null;
        LAndExp lAndExp = new LAndExp(eqExp);
        addSyntax(SyntaxType.LAndExp);
        while (peek().getType() == Token.TokenType.AND) {
            next();
            EqExp eqExp2 = parseEqExp();
            if (eqExp2 == null) return null;
            lAndExp = new LAndExp(lAndExp, eqExp2);
            addSyntax(SyntaxType.LAndExp);
        }
        return lAndExp;
    }

    public EqExp parseEqExp() {
        RelExp relExp = parseRelExp();
        if (relExp == null) return null;
        EqExp eqExp = new EqExp(relExp);
        addSyntax(SyntaxType.EqExp);
        while (peek().getType() == Token.TokenType.EQL
                || peek().getType() == Token.TokenType.NEQ) {
            Token.TokenType eqOp = peek().getType();
            next();
            RelExp relExp2 = parseRelExp();
            if (relExp2 == null) return null;
            eqExp = new EqExp(eqExp, eqOp, relExp2);
            addSyntax(SyntaxType.EqExp);
        }
        return eqExp;
    }

    public RelExp parseRelExp() {
        AddExp addExp = parseAddExp();
        if (addExp == null) return null;
        RelExp relExp = new RelExp(addExp);
        addSyntax(SyntaxType.RelExp);
        while (peek().getType() == Token.TokenType.LSS || peek().getType() == Token.TokenType.LEQ
                || peek().getType() == Token.TokenType.GRE || peek().getType() == Token.TokenType.GEQ) {
            Token.TokenType relOp = peek().getType();
            next();
            AddExp addExp2 = parseAddExp();
            if (addExp2 == null) return null;
            relExp = new RelExp(relExp, relOp, addExp2);
            addSyntax(SyntaxType.RelExp);
        }
        return relExp;
    }

    public LVal parseLVal() {
        if (peek().getType() != Token.TokenType.IDENFR) return null;
        Ident ident = new Ident(peek().getValue(), Ident.Type.VAR);
        next();
        Exp index = null;
        if (peek().getType() == Token.TokenType.LBRACK) {
            next();
            index = parseExp();
            if (index == null) return null;
            checkRBRACK();
        }
        addSyntax(SyntaxType.LVal);
        return new LVal(ident, index);
    }

    public ConstExp parseConstExp() {
        AddExp addExp = parseAddExp();
        if (addExp == null) return null;
        addSyntax(SyntaxType.ConstExp);
        return new ConstExp(addExp);
    }

    public Number parseNumber() {
        if (peek().getType() != Token.TokenType.INTCON) {
            return null;
        } else {
            Number number = new Number(peek());
            next();
            addSyntax(SyntaxType.Number);
            return number;
        }
    }

    public Character parseCharacter() {
        if (peek().getType() != Token.TokenType.CHRCON) {
            return null;
        } else {
            Character character = new Character(peek());
            next();
            addSyntax(SyntaxType.Character);
            return character;
        }
    }

    public void checkSEMICN() {
        if (peek().getType() != Token.TokenType.SEMICN) {
            addError(getPrevTokenLineNum(), "i");
        } else {
            next();
        }
    }

    public void checkRPARENT() {
        if (peek().getType() != Token.TokenType.RPARENT) {
            addError(getPrevTokenLineNum(), "j");
        } else {
            next();
        }
    }

    public void checkRBRACK() {
        if (peek().getType() != Token.TokenType.RBRACK) {
            addError(getPrevTokenLineNum(), "k");
        } else {
            next();
        }
    }

    public boolean isBType(Token token) {
        return token.getType() == Token.TokenType.INTTK
                || token.getType() == Token.TokenType.CHARTK;
    }

    public boolean isFuncType(Token token) {
        return token.getType() == Token.TokenType.VOIDTK
                || isBType(token);
    }

    public boolean isUnaryOp(Token token) {
        return token.getType() == Token.TokenType.NOT
                || token.getType() == Token.TokenType.PLUS
                || token.getType() == Token.TokenType.MINU;
    }

    public void addError(int line, String errorType) {
        Error error = new Error(line, errorType);
        errorList.add(error);
    }
}