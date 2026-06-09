package frontend.parser;

import frontend.Tree.Character;
import frontend.Tree.Number;
import frontend.Lexer.LexType;
import frontend.Lexer.Lexer;
import frontend.Tree.*;
import frontend.Error.ErrorTool;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Parser {
    private Lexer lexer;
    private String token;
    private LexType lexType;
    private boolean outputParser = true;
    private boolean outputLexer = true;
    private BufferedWriter writer1;
    private ErrorTool errorTool;

    public Parser(Lexer lexer, BufferedWriter writer1, ErrorTool errorTool) throws IOException {
        this.lexer = lexer;
        this.writer1 = writer1;
        this.errorTool = errorTool;
        getToken();
    }

    public boolean getToken() throws IOException {
        if (token != null && outputLexer) {
            //System.out.println(token);
            writer1.write(lexer.getLexType() + " " + lexer.getToken() + "\n");
        }
        while (lexer.next()) {
            if (lexer.getLexType() != LexType.NOTE) {
                if (lexer.isError()) {
                    errorTool.checkA(lexer.getLineNum());
                }
                token = lexer.getToken();
                lexType = lexer.getLexType();
                return true;
            }
        }
        return false;
    }

    private void outputP(String a) throws IOException {
        if (outputParser) {
            writer1.write("<" + a + ">\n");
            //System.out.println("<" + a + ">");
        }
    }

    public CompUnit parseCompUnit() throws IOException {
        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        ArrayList<LexType> lexTypes = lexer.preRead(2);
        while (lexTypes.get(0) != LexType.MAINTK) {
            if (lexTypes.get(1) == LexType.LPARENT) {
                FuncDef funcDef = parseFuncDef();
                funcDefs.add(funcDef);
            } else {
                Decl decl = parseDecl();
                decls.add(decl);
            }
            lexTypes = lexer.preRead(2);
        }
        MainFuncDef mainFuncDef = parseMainFuncDef();
        CompUnit compUnit = new CompUnit(decls, funcDefs, mainFuncDef);
        outputP("CompUnit");
        return compUnit;
    }

    public Decl parseDecl() throws IOException {
        Decl decl;
        if (lexType == LexType.CONSTTK) {
            decl = new Decl(parseConstDecl());
        } else {
            decl = new Decl(parseVarDecl());
        }
        return decl;
    }

    public ConstDecl parseConstDecl() throws IOException {
        int line = lexer.getLineNum();
        getToken();
        BType bType = parseBType();
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        ConstDef constDef = parseConstDef();
        constDefs.add(constDef);
        while (lexType == LexType.COMMA) {
            getToken();
            constDef = parseConstDef();
            constDefs.add(constDef);
        }
        if (errorTool.checkI(token, line)) {
            getToken();
        }
        outputP("ConstDecl");
        return new ConstDecl(bType, constDefs);
    }

    public BType parseBType() throws IOException {
        BType bType;
        if (lexType == LexType.INTTK) {
            bType = new BType(lexType);
        } else if (lexType == LexType.CHARTK) {
            bType = new BType(lexType);
        } else {
            bType = null;
        }
        getToken();
        return bType;
    }

    public ConstDef parseConstDef() throws IOException {
        int line = lexer.getLineNum();
        String ident = token;
        ConstExp constExp = null;
        getToken();
        if (lexType == LexType.LBRACK) {
            int line1 = lexer.getLineNum();
            getToken();
            constExp = parseConstExp();
            if (errorTool.checkK(token, line)) {
                getToken();
            }
        }
        getToken();
        ConstInitVal constInitVal = parseConstInitVal();
        outputP("ConstDef");
        return new ConstDef(getIdent(ident, line), constExp, constInitVal);
    }

    public ConstInitVal parseConstInitVal() throws IOException {
        if (lexType == LexType.STRCON) {
            String s = token;
            getToken();
            outputP("ConstInitVal");
            return new ConstInitVal(s);
        }
        ArrayList<ConstExp> constExps = new ArrayList<>();
        if (lexType == LexType.LBRACE) {
            getToken();
            if (lexType != LexType.RBRACE) {
                constExps.add(parseConstExp());
                while (lexType == LexType.COMMA) {
                    getToken();
                    constExps.add(parseConstExp());
                }
            }
            getToken();
        } else {
            constExps.add(parseConstExp());
        }
        outputP("ConstInitVal");
        return new ConstInitVal(constExps);
    }

    public VarDecl parseVarDecl() throws IOException {
        int line = lexer.getLineNum();
        BType bType = parseBType();
        ArrayList<VarDef> varDefs = new ArrayList<>();
        varDefs.add(parseVarDef());
        while (lexType == LexType.COMMA) {
            getToken();
            varDefs.add(parseVarDef());
        }
        if (errorTool.checkI(token, line)) {
            getToken();
        }
        outputP("VarDecl");
        return new VarDecl(bType, varDefs);
    }

    public VarDef parseVarDef() throws IOException {
        int line = lexer.getLineNum();
        String ident = token;
        ConstExp constExp = null;
        InitVal initVal = null;
        getToken();
        if (lexType == LexType.LBRACK) {
            int line1 = lexer.getLineNum();
            getToken();
            constExp = parseConstExp();
            if (errorTool.checkK(token, line)) {
                getToken();
            }
        }
        if (lexType == LexType.ASSIGN) {
            getToken();
            initVal = parseInitVal();
        }
        outputP("VarDef");
        return new VarDef(getIdent(ident, line), constExp, initVal);
    }

    public InitVal parseInitVal() throws IOException {
        ArrayList<Exp> exps = new ArrayList<>();
        if (lexType == LexType.LBRACE) {
            getToken();
            exps.add(parseExp());
            while (lexType == LexType.COMMA) {
                getToken();
                exps.add(parseExp());
            }
            getToken();
        } else {
            if (lexType == LexType.STRCON) {
                String s = token;
                getToken();
                outputP("InitVal");
                return new InitVal(s);
            } else {
                exps.add(parseExp());
            }
        }
        outputP("InitVal");
        return new InitVal(exps);
    }

    public FuncDef parseFuncDef() throws IOException {
        FuncType funcType = parseFuncType();
        int line = lexer.getLineNum();
        String ident = token;
        FuncFParams funcFParams = null;
        getToken();
        getToken();
        if (lexType != LexType.RPARENT) {
            funcFParams = parseFuncFParams();
        }
        if (errorTool.checkJ(token, line)) {
            getToken();
        }
        Block block = parseBlock();
        outputP("FuncDef");
        return new FuncDef(funcType, getIdent(ident, line), funcFParams, block);
    }

    public MainFuncDef parseMainFuncDef() throws IOException {
        int line = lexer.getLineNum();
        getToken();
        getToken();
        getToken();
        if (errorTool.checkJ(token, line)) {
            getToken();
        }
        Block block = parseBlock();
        outputP("MainFuncDef");
        return new MainFuncDef(block);
    }

    public FuncType parseFuncType() throws IOException {
        LexType op = lexType;
        getToken();
        outputP("FuncType");
        return new FuncType(op);
    }

    public FuncFParam parseFuncFParam() throws IOException {int line = lexer.getLineNum();
        BType bType = parseBType();

        String ident = token;
        getToken();
        if (lexType == LexType.LBRACK) {
            getToken();
            if (errorTool.checkK(token, line)) {
                getToken();
            }
        }
        outputP("FuncFParam");
        return new FuncFParam(bType, getIdent(ident,line));
    }

    public FuncFParams parseFuncFParams() throws IOException {
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        FuncFParam funcFParam = parseFuncFParam();
        funcFParams.add(funcFParam);
        while (lexType == LexType.COMMA) {
            getToken();
            funcFParams.add(parseFuncFParam());
        }
        outputP("FuncFParams");
        return new FuncFParams(funcFParams);
    }

    public Block parseBlock() throws IOException {
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        getToken();
        while (lexType != LexType.RBRACE) {
            BlockItem blockItem = parseBlockItem();
            blockItems.add(blockItem);
        }
        getToken();
        outputP("Block");
        return new Block(blockItems);
    }

    public BlockItem parseBlockItem() throws IOException {
        BlockItem blockItem;
        if (lexType == LexType.CONSTTK || lexType == LexType.INTTK
                || lexType == LexType.CHARTK) {
            blockItem = new BlockItem(parseDecl());
        } else {
            blockItem = new BlockItem(parseStmt());
        }
        return blockItem;
    }

    public Stmt parseStmt() throws IOException {
        int line = lexer.getLineNum();
        if (lexType == LexType.IFTK) {
            getToken();
            getToken();
            Cond cond = parseCond();
            if (errorTool.checkJ(token, line)) {
                getToken();
            }
            Stmt stmt = parseStmt();
            Stmt stmt1 = null;
            if (lexType == LexType.ELSETK) {
                getToken();
                stmt1 = parseStmt();
            }
            outputP("Stmt");
            return new Stmt(cond, stmt, stmt1, StmtType.If);
        } else if (lexType == LexType.FORTK) {
            ForStmt forStmt = null;
            Cond cond = null;
            ForStmt forStmt1 = null;
            Stmt stmt;
            getToken();
            getToken();
            if (lexType != LexType.SEMICN) {
                forStmt = parseForStmt();
            }
            getToken();
            if (lexType != LexType.SEMICN) {
                cond = parseCond();
            }
            getToken();
            if (lexType != LexType.RPARENT) {
                forStmt1 = parseForStmt();
            }
            getToken();
            stmt = parseStmt();
            outputP("Stmt");
            return new Stmt(forStmt, cond, forStmt1, stmt, StmtType.For);
        } else if (lexType == LexType.BREAKTK) {
            getToken();
            if (errorTool.checkI(token, line)) {
                getToken();
            }
            outputP("Stmt");
            return new Stmt(StmtType.Break);
        } else if (lexType == LexType.CONTINUETK) {
            getToken();
            if (errorTool.checkI(token, line)) {
                getToken();
            }
            outputP("Stmt");
            return new Stmt(StmtType.Continue);
        } else if (lexType == LexType.RETURNTK) {
            getToken();
            Exp exp = null;
            if (lexType != LexType.SEMICN) {
                exp = parseExp();
            }
            if (errorTool.checkI(token, line)) {
                getToken();
            }
            outputP("Stmt");
            return new Stmt(exp, StmtType.Return, StmtType.Return);
        } else if (lexType == LexType.PRINTFTK) {
            getToken();
            getToken();
            String s = token;
            getToken();
            ArrayList<Exp> exps = new ArrayList<>();
            while (lexType == LexType.COMMA) {
                getToken();
                exps.add(parseExp());
            }
            if (errorTool.checkJ(token, line)) {
                getToken();
            }
            if (errorTool.checkI(token, line)) {
                getToken();
            }
            outputP("Stmt");
            return new Stmt(s, exps, StmtType.Printf);
        } else if (lexType == LexType.LBRACE) {
            Block block = parseBlock();
            outputP("Stmt");
            return new Stmt(block, StmtType.Block);
        } else if (lexer.preReadCompare(LexType.ASSIGN)) {
            LVal lVal = parseLVal();
            getToken();
            //System.out.println(lexType);
            if (lexType == LexType.GETINTTK) {
                getToken();
                getToken();
                if (errorTool.checkJ(token, line)) {
                    getToken();
                }
                if (errorTool.checkI(token, line)) {
                    getToken();
                }
                outputP("Stmt");
                return new Stmt(lVal, StmtType.Getint);
            } else if (lexType == LexType.GETCHARTK) {
                getToken();
                getToken();
                if (errorTool.checkJ(token, line)) {
                    getToken();
                }
                if (errorTool.checkI(token, line)) {
                    getToken();
                }
                outputP("Stmt");
                return new Stmt(lVal, StmtType.Getchar);
            } else {
                Exp exp = parseExp();
                if (errorTool.checkI(token, line)) {
                    getToken();
                }
                outputP("Stmt");
                return new Stmt(lVal, exp, StmtType.LValExp);
            }
        } else {
            Exp exp = null;
            if (lexType != LexType.SEMICN) {
                exp = parseExp();
            }
            if (errorTool.checkI(token, line)) {
                getToken();
            }
            outputP("Stmt");
            return new Stmt(exp, StmtType.EXP);
        }
    }

    public ForStmt parseForStmt() throws IOException {
        LVal lVal = parseLVal();
        getToken();
        Exp exp = parseExp();
        outputP("ForStmt");
        return new ForStmt(lVal, exp);
    }

    public Exp parseExp() throws IOException {
        AddExp addExp = parseAddExp();
        outputP("Exp");
        return new Exp(addExp);
    }

    public Cond parseCond() throws IOException {
        LOrExp lOrExp = parseLOrExp();
        outputP("Cond");
        return new Cond(lOrExp);
    }

    public LVal parseLVal() throws IOException {
        int line = lexer.getLineNum();
        String s = token;
        Exp exp = null;
        getToken();
        if (lexType == LexType.LBRACK) {
            getToken();
            exp = parseExp();
            if (errorTool.checkK(token, line)) {
                getToken();
            }
        }
        if (exp == null) {
            outputP("LVal");
            return new LVal(getIdent(s,line));
        } else {
            outputP("LVal");
            return new LVal(getIdent(s,line), exp);
        }
    }

    public PrimaryExp parsePrimaryExp() throws IOException {
        int line = lexer.getLineNum();
        if (lexType == LexType.INTCON) {
            Number number = parseNumber();
            outputP("PrimaryExp");
            return new PrimaryExp(number);
        } else if (lexType == LexType.CHRCON) {
            Character character = parseCharacter();
            outputP("PrimaryExp");
            return new PrimaryExp(character);
        } else if (lexType == LexType.IDENFR) {
            LVal lVal = parseLVal();
            outputP("PrimaryExp");
            return new PrimaryExp(lVal);
        } else {
            getToken();
            Exp exp = parseExp();
            if (errorTool.checkJ(token, line)) {
                getToken();
            }
            outputP("PrimaryExp");
            return new PrimaryExp(exp);
        }
    }

    public Number parseNumber() throws IOException {
        Number number = new Number(token);
        getToken();
        outputP("Number");
        return number;
    }

    public Character parseCharacter() throws IOException {
        Character character = new Character(token);
        getToken();
        outputP("Character");
        return character;
    }

    public UnaryExp parseUnaryExp() throws IOException {int line = lexer.getLineNum();
        if (lexType == LexType.PLUS || lexType == LexType.MINU
                || lexType == LexType.NOT) {
            UnaryOp op = parseUnaryOp();
            UnaryExp unaryExp = parseUnaryExp();
            outputP("UnaryExp");
            return new UnaryExp(op, unaryExp);
        } else if (lexType == LexType.IDENFR) {
            ArrayList<LexType> lexTypes = lexer.preRead(1);
            if (lexTypes.get(0) == LexType.LPARENT) {

                String s = token;
                getToken();
                getToken();
                FuncRParams funcRParams = null;
                if (lexType != LexType.RPARENT&&lexer.preReadCompare(LexType.RPARENT)) {
                    funcRParams = parseFuncRParams();
                }
                if (errorTool.checkJ(token, line)) {
                    getToken();
                }
                outputP("UnaryExp");
                return new UnaryExp(getIdent(s,line), funcRParams);
            } else {
                PrimaryExp primaryExp = parsePrimaryExp();
                outputP("UnaryExp");
                return new UnaryExp(primaryExp);
            }
        } else {
            PrimaryExp primaryExp = parsePrimaryExp();
            outputP("UnaryExp");
            return new UnaryExp(primaryExp);
        }
    }

    public UnaryOp parseUnaryOp() throws IOException {
        LexType op = lexType;
        getToken();
        outputP("UnaryOp");
        return new UnaryOp(op);
    }

    public FuncRParams parseFuncRParams() throws IOException {
        ArrayList<Exp> exps = new ArrayList<>();
        Exp exp = parseExp();
        exps.add(exp);
        while (lexType == LexType.COMMA) {
            getToken();
            exp = parseExp();
            exps.add(exp);
        }
        outputP("FuncRParams");
        return new FuncRParams(exps);
    }

    public MulExp parseMulExp() throws IOException {
        UnaryExp unaryExp = parseUnaryExp();
        MulExp mulExp = new MulExp(unaryExp);
        outputP("MulExp");
        while (lexType == LexType.MULT || lexType == LexType.DIV
                || lexType == LexType.MOD) {
            LexType op = lexType;
            getToken();
            unaryExp = parseUnaryExp();
            outputP("MulExp");
            mulExp = new MulExp(unaryExp, op, mulExp);
        }
        return mulExp;
    }

    public AddExp parseAddExp() throws IOException {
        MulExp mulExp = parseMulExp();
        AddExp addExp = new AddExp(mulExp);
        outputP("AddExp");
        while (lexType == LexType.PLUS || lexType == LexType.MINU) {
            LexType op = lexType;
            getToken();
            mulExp = parseMulExp();
            outputP("AddExp");
            addExp = new AddExp(addExp, op, mulExp);
        }
        return addExp;
    }

    public RelExp parseRelExp() throws IOException {
        AddExp addExp = parseAddExp();
        RelExp relExp = new RelExp(addExp);
        outputP("RelExp");
        while (lexType == LexType.LSS || lexType == LexType.GRE
                || lexType == LexType.GEQ || lexType == LexType.LEQ) {
            LexType op = lexType;
            getToken();
            addExp = parseAddExp();
            outputP("RelExp");
            relExp = new RelExp(relExp, op, addExp);
        }
        return relExp;
    }

    public EqExp parseEqExp() throws IOException {
        RelExp relExp = parseRelExp();
        EqExp eqExp = new EqExp(relExp);
        outputP("EqExp");
        while (lexType == LexType.EQL || lexType == LexType.NEQ) {
            LexType op = lexType;
            getToken();
            relExp = parseRelExp();
            outputP("EqExp");
            eqExp = new EqExp(eqExp, op, relExp);
        }
        return eqExp;
    }

    public LAndExp parseLAndExp() throws IOException {
        EqExp eqExp = parseEqExp();
        LAndExp lAndExp = new LAndExp(eqExp);
        outputP("LAndExp");
        while (lexType == LexType.AND || token.equals("&")) {
            getToken();
            eqExp = parseEqExp();
            outputP("LAndExp");
            lAndExp = new LAndExp(lAndExp, eqExp);
        }
        return lAndExp;
    }

    public LOrExp parseLOrExp() throws IOException {
        LAndExp lAndExp = parseLAndExp();
        LOrExp lOrExp = new LOrExp(lAndExp);
        outputP("LOrExp");
        while (lexType == LexType.OR || token.equals("|")) {
            getToken();
            lAndExp = parseLAndExp();
            outputP("LOrExp");
            lOrExp = new LOrExp(lOrExp, lAndExp);
        }
        return lOrExp;
    }

    public ConstExp parseConstExp() throws IOException {
        AddExp addExp = parseAddExp();
        outputP("ConstExp");
        return new ConstExp(addExp);
    }

    public Ident getIdent(String ident, int line) {
        return new Ident(ident, line);
    }
}
