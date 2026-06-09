package frontend.parser;

import frontend.ErrorList;
import frontend.lexer.TokenStream;
import frontend.lexer.TokenType;
import frontend.parser.base.CompUnit;
import frontend.parser.base.Lval;
import frontend.parser.exp.*;
import frontend.parser.func.*;
import frontend.parser.stmt.*;
import frontend.parser.stmt.Decl.*;

import java.util.ArrayList;

public class Parser {
    private TokenStream tokenStream;
    private ErrorList errorList;
    private TokenStream.Token token;

    public Parser(TokenStream tokenStream, ErrorList errorList) {
        this.tokenStream = tokenStream;
        this.errorList = errorList;
        this.token = this.tokenStream.getToken();
    }

    public CompUnit parseCompUnit() {
        ArrayList<DeclStmt> declStmts = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        MainFuncDef mainFuncDef;
        this.tokenStream.move();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        this.tokenStream.back(2);
        while (this.token.getTokenType() != TokenType.LPARENT) {
            declStmts.add(parseDecl());
            this.tokenStream.move();
            this.tokenStream.move();
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
            this.tokenStream.back(2);
        }
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        this.tokenStream.back(1);
        while (this.token.getTokenType() != TokenType.MAINTK) {
            funcDefs.add(parseFuncDef());
            this.tokenStream.move();
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
            this.tokenStream.back(1);
        }
        mainFuncDef = parseMainFuncDef();
        return new CompUnit(declStmts, funcDefs, mainFuncDef);
    }

    public DeclStmt parseDecl() {
        this.token = this.tokenStream.getToken();
        if (ConstDecl.FIRST.contains(this.token.getTokenType())) {
            return parseConstDecl();
        } else {
            return parseVarDecl();
        }
    }

    public VarDecl parseVarDecl() {
        TokenType BType;
        ArrayList<VarDef> varDefs = new ArrayList<>();
        this.token = this.tokenStream.getToken();
        BType = this.token.getTokenType();
        do {
            this.tokenStream.move();
            varDefs.add(parseVarDef());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        } while(this.token.getTokenType() == TokenType.COMMA);
        this.tokenStream.back(1);
        expect(TokenType.SEMICN);
        return new VarDecl(BType, varDefs);
    }

    public VarDef parseVarDef() {
        String Ident;
        ConstExp constExp = null;
        InitVal initVal = null;
        this.token = this.tokenStream.getToken();
        Ident = String.valueOf(this.token.getContent());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (this.token.getTokenType() == TokenType.LBRACK) {
            this.tokenStream.move();
            constExp = parseConstExp();
            expect(TokenType.RBRACK);
        } else {
            this.tokenStream.back(1);
        }
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (this.token.getTokenType() == TokenType.ASSIGN) {
            this.tokenStream.move();
            initVal = parseInitVal();
        } else {
            this.tokenStream.back(1);
        }
        return new VarDef(Ident, constExp, initVal);
    }

    public InitVal parseInitVal() {
        this.token = this.tokenStream.getToken();
        if (ArrayInitVal.FIRST.contains(this.token.getTokenType())) {
            return parseArrayInitVal();
        } else if (ExpInitVal.FIRST.contains(this.token.getTokenType())) {
            return parseExpInitVal();
        } else {
            return parseStringInitVal();
        }
    }

    public ArrayInitVal parseArrayInitVal() {
        ArrayList<Exp> exps = new ArrayList<>();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (Exp.FIRST.contains(this.token.getTokenType())) {
            exps.add(parseExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
            while (this.token.getTokenType() == TokenType.COMMA) {
                this.tokenStream.move();
                exps.add(parseExp());
                this.tokenStream.move();
                this.token = this.tokenStream.getToken();
            }
        }
        return new ArrayInitVal(exps);
    }

    public ExpInitVal parseExpInitVal() {
        return new ExpInitVal(parseExp());
    }

    public StringInitVal parseStringInitVal() {
        this.token = this.tokenStream.getToken();
        return new StringInitVal(String.valueOf(this.token.getContent()));
    }

    public ConstDecl parseConstDecl() {
        TokenType BType;
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        BType = token.getTokenType();
        do {
            this.tokenStream.move();
            constDefs.add(parseConstDef());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        } while(this.token.getTokenType() == TokenType.COMMA);
        this.tokenStream.back(1);
        expect(TokenType.SEMICN);
        return new ConstDecl(BType, constDefs);
    }

    public ConstDef parseConstDef() {
        String Ident;
        ConstExp constExp = null;
        ConstInitVal constInitVal;
        this.token = this.tokenStream.getToken();
        Ident = String.valueOf(this.token.getContent());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (token.getTokenType() == TokenType.LBRACK) {
            this.tokenStream.move();
            constExp = parseConstExp();
            expect(TokenType.RBRACK);
        } else {
            this.tokenStream.back(1);
        }
        this.tokenStream.move();
        this.tokenStream.move();
        constInitVal = parseConstInitVal();
        return new ConstDef(Ident, constExp, constInitVal);
    }

    public ConstExp parseConstExp() {
        return new ConstExp(parseAddExp());
    }

    public AddExp parseAddExp() {
        ArrayList<MulExp> mulExps = new ArrayList<>();
        ArrayList<TokenType> signs = new ArrayList<>();
        mulExps.add(parseMulExp());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.PLUS || this.token.getTokenType() == TokenType.MINU) {
            signs.add(this.token.getTokenType());
            this.tokenStream.move();
            mulExps.add(parseMulExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        return new AddExp(mulExps, signs);
    }

    public MulExp parseMulExp() {
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<TokenType> signs = new ArrayList<>();
        unaryExps.add(parseUnaryExp());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.MULT || this.token.getTokenType() == TokenType.DIV || this.token.getTokenType() == TokenType.MOD) {
            signs.add(this.token.getTokenType());
            this.tokenStream.move();
            unaryExps.add(parseUnaryExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        return new MulExp(unaryExps, signs);
    }

    public UnaryExp parseUnaryExp() {
        this.token = this.tokenStream.getToken();
        ArrayList<TokenType> signs = new ArrayList<>();
        while (this.token.getTokenType() == TokenType.PLUS || this.token.getTokenType() == TokenType.MINU || this.token.getTokenType() == TokenType.NOT) {
            signs.add(this.token.getTokenType());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        if (this.token.getTokenType() == TokenType.IDENFR) {
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
            this.tokenStream.back(1);
            if (this.token.getTokenType() == TokenType.LPARENT) {
                return parseCallFuncUnaryExp(signs);
            } else {
                return parsePrimaryUnaryExp(signs);
            }
        } else {
            return parsePrimaryUnaryExp(signs);
        }
    }

    public CallFuncUnaryExp parseCallFuncUnaryExp(ArrayList<TokenType> signs) {
        String Ident;
        FuncRParams funcRParams = null;
        this.token = this.tokenStream.getToken();
        Ident = String.valueOf(this.token.getContent());
        this.tokenStream.move();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (FuncRParams.FIRST.contains(this.token.getTokenType())) {
            funcRParams = parseFuncRParams();
        } else {
            this.tokenStream.back(1);
        }
        expect(TokenType.RPARENT);
        return new CallFuncUnaryExp(signs, Ident, funcRParams);
    }

    public FuncRParams parseFuncRParams() {
        ArrayList<Exp> exps = new ArrayList<>();
        exps.add(parseExp());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.COMMA) {
            this.tokenStream.move();
            exps.add(parseExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        return new FuncRParams(exps);
    }

    public Exp parseExp() {
        return new Exp(parseAddExp());
    }

    public PrimaryUnaryExp parsePrimaryUnaryExp(ArrayList<TokenType> signs) {
        return new PrimaryUnaryExp(signs, parsePrimaryExp());
    }

    public PrimaryExp parsePrimaryExp() {
        this.token = this.tokenStream.getToken();
        if (CharPrimaryExp.FIRST.contains(this.token.getTokenType())) {
            return parseCharPrimaryExp();
        } else if (ExpPrimaryExp.FIRST.contains(this.token.getTokenType())) {
            return parseExpPrimaryExp();
        } else if (LvalPrimaryExp.FIRST.contains(this.token.getTokenType())) {
            return parseLvalPrimaryExp();
        } else {
            return parseNumPrimaryExp();
        }
    }

    public CharPrimaryExp parseCharPrimaryExp() {
        this.token = this.tokenStream.getToken();
        return new CharPrimaryExp(this.token.getContent());
    }

    public ExpPrimaryExp parseExpPrimaryExp() {
        Exp exp;
        this.tokenStream.move();
        exp = parseExp();
        expect(TokenType.RPARENT);
        return new ExpPrimaryExp(exp);
    }

    public LvalPrimaryExp parseLvalPrimaryExp() {
        return new LvalPrimaryExp(parseLval());
    }

    public Lval parseLval() {
        String Ident;
        Exp exp = null;
        this.token = this.tokenStream.getToken();
        Ident = String.valueOf(this.token.getContent());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (this.token.getTokenType() == TokenType.LBRACK) {
            this.tokenStream.move();
            exp = parseExp();
            expect(TokenType.RBRACK);
        } else {
            this.tokenStream.back(1);
        }
        return new Lval(Ident, exp);
    }

    public NumPrimaryExp parseNumPrimaryExp() {
        this.token = this.tokenStream.getToken();
        return new NumPrimaryExp(String.valueOf(this.token.getContent()));
    }

    public ConstInitVal parseConstInitVal() {
        this.token = this.tokenStream.getToken();
        if (ExpConstInitVal.FIRST.contains(token.getTokenType())) {
            return parseExpConstInitVal();
        } else if (ArrayConstInitVal.FIRST.contains(token.getTokenType())) {
            return parseArrayConstInitVal();
        } else {
            return parseStringConstInitVal();
        }
    }

    public ExpConstInitVal parseExpConstInitVal() {
        return new ExpConstInitVal(parseConstExp());
    }

    public ArrayConstInitVal parseArrayConstInitVal() {
        ArrayList<ConstExp> constExps = new ArrayList<>();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (ConstExp.FIRST.contains(this.token.getTokenType())) {
            constExps.add(parseConstExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
            while (this.token.getTokenType() == TokenType.COMMA) {
                this.tokenStream.move();
                constExps.add(parseConstExp());
                this.tokenStream.move();
                this.token = this.tokenStream.getToken();
            }
        }
        return new ArrayConstInitVal(constExps);
    }

    public StringConstInitVal parseStringConstInitVal() {
        this.token = this.tokenStream.getToken();
        return new StringConstInitVal(this.token.getContent());
    }

    public FuncDef parseFuncDef() {
        TokenType FuncType;
        String Ident;
        FuncFParams funcFParams = null;
        Block block;
        this.token = this.tokenStream.getToken();
        FuncType = this.token.getTokenType();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        Ident = String.valueOf(this.token.getContent());
        this.tokenStream.move();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (FuncFParams.FIRST.contains(this.token.getTokenType())) {
            funcFParams = parseFuncFParams();
        } else {
            this.tokenStream.back(1);
        }
        expect(TokenType.RPARENT);
        this.tokenStream.move();
        block = parseBlock();
        return new FuncDef(FuncType, Ident, funcFParams, block);
    }

    public FuncFParams parseFuncFParams() {
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        funcFParams.add(parseFuncFParam());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.COMMA) {
            this.tokenStream.move();
            funcFParams.add(parseFuncFParam());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        return new FuncFParams(funcFParams);
    }

    public FuncFParam parseFuncFParam() {
        TokenType BType;
        String Ident;
        boolean isArray;
        this.token = this.tokenStream.getToken();
        BType = this.token.getTokenType();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        Ident = String.valueOf(this.token.getContent());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (this.token.getTokenType() == TokenType.LBRACK) {
            isArray = true;
            expect(TokenType.RBRACK);
        } else {
            isArray = false;
            this.tokenStream.back(1);
        }
        return new FuncFParam(BType, Ident, isArray);
    }

    public Block parseBlock() {
        ArrayList<Stmt> stmts = new ArrayList<>();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (Stmt.FIRST.contains(this.token.getTokenType())) {
            stmts.add(parseStmt());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        return new Block(stmts);
    }

    public Stmt parseStmt() {
        this.token = this.tokenStream.getToken();
        if (this.token.getTokenType() == TokenType.LBRACE) {
            return parseBlockStmt();
        } else if (this.token.getTokenType() == TokenType.IFTK) {
            return parseIfStmt();
        } else if (this.token.getTokenType() == TokenType.FORTK) {
            return parseForStmt();
        } else if (this.token.getTokenType() == TokenType.BREAKTK) {
            return parseBreakStmt();
        } else if (this.token.getTokenType() == TokenType.CONTINUETK) {
            return parseContinueStmt();
        } else if (this.token.getTokenType() == TokenType.RETURNTK) {
            return parseReturnStmt();
        } else if (this.token.getTokenType() == TokenType.PRINTFTK) {
            return parsePrintfStmt();
        } else if (DeclStmt.FIRST.contains(this.token.getTokenType())){
            return parseDecl();
        } else {
            int nowPos = this.tokenStream.getPos();
            parseExp();
            int len = this.tokenStream.getPos() - nowPos;
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
            if (this.token.getTokenType() == TokenType.ASSIGN) {
                this.tokenStream.move();
                this.token = this.tokenStream.getToken();
                this.tokenStream.back(len + 2);
                if (this.token.getTokenType() == TokenType.GETCHARTK) {
                    return parseGetCharStmt();
                } else if (this.token.getTokenType() == TokenType.GETINTTK) {
                    return parseGetIntStmt();
                } else {
                    return parseAssignStmt();
                }
            } else {
                this.tokenStream.back(len + 1);
                return parseExpStmt();
            }
        }
    }

    public AssignStmt parseAssignStmt() {
        Lval lval;
        Exp exp;
        lval = parseLval();
        this.tokenStream.move();
        this.tokenStream.move();
        exp = parseExp();
        expect(TokenType.SEMICN);
        return new AssignStmt(lval, exp);
    }

    public BlockStmt parseBlockStmt() {
        return new BlockStmt(parseBlock());
    }

    public BreakStmt parseBreakStmt() {
        expect(TokenType.SEMICN);
        return new BreakStmt();
    }

    public ContinueStmt parseContinueStmt() {
        expect(TokenType.SEMICN);
        return new ContinueStmt();
    }

    public ExpStmt parseExpStmt() {
        Exp exp = null;
        this.token = this.tokenStream.getToken();
        if (Exp.FIRST.contains(this.token.getTokenType())) {
            exp = parseExp();
            expect(TokenType.SEMICN);
        }
        return new ExpStmt(exp);
    }

    public ForStmt parseForStmt() {
        ForAssign forAssign1 = null;
        ForAssign forAssign2 = null;
        Cond cond = null;
        Stmt stmt;
        this.tokenStream.move();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (ForAssign.FIRST.contains(this.token.getTokenType())) {
            forAssign1 = parseForAssign();
        } else {
            this.tokenStream.back(1);
        }
        expect(TokenType.SEMICN);
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (Cond.FIRST.contains(this.token.getTokenType())) {
            cond = parseCond();
        } else {
            this.tokenStream.back(1);
        }
        expect(TokenType.SEMICN);
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (ForAssign.FIRST.contains(this.token.getTokenType())) {
            forAssign2 = parseForAssign();
        } else {
            this.tokenStream.back(1);
        }
        expect(TokenType.RPARENT);
        this.tokenStream.move();
        stmt = parseStmt();
        return new ForStmt(forAssign1, forAssign2, cond, stmt);
    }

    public ForAssign parseForAssign() {
        Lval lval;
        Exp exp;
        lval = parseLval();
        this.tokenStream.move();
        this.tokenStream.move();
        exp = parseExp();
        return new ForAssign(lval, exp);
    }

    public Cond parseCond() {
        return new Cond(parseLOrExp());
    }

    public LOrExp parseLOrExp() {
        ArrayList<LAndExp> lAndExps = new ArrayList<>();
        ArrayList<TokenType> signs = new ArrayList<>();
        lAndExps.add(parseLAndExp());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.OR) {
            signs.add(this.token.getTokenType());
            this.tokenStream.move();
            lAndExps.add(parseLAndExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        return new LOrExp(lAndExps, signs);
    }

    public LAndExp parseLAndExp() {
        ArrayList<EqExp> eqExps = new ArrayList<>();
        ArrayList<TokenType> signs = new ArrayList<>();
        eqExps.add(parseEqExp());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.AND) {
            signs.add(this.token.getTokenType());
            this.tokenStream.move();
            eqExps.add(parseEqExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        return new LAndExp(eqExps, signs);
    }

    public EqExp parseEqExp() {
        ArrayList<RelExp> relExps = new ArrayList<>();
        ArrayList<TokenType> signs = new ArrayList<>();
        relExps.add(parseRelExp());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.EQL || this.token.getTokenType() == TokenType.NEQ) {
            signs.add(this.token.getTokenType());
            this.tokenStream.move();
            relExps.add(parseRelExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        return new EqExp(relExps, signs);
    }

    public RelExp parseRelExp() {
        ArrayList<AddExp> addExps = new ArrayList<>();
        ArrayList<TokenType> signs = new ArrayList<>();
        addExps.add(parseAddExp());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.LSS || this.token.getTokenType() == TokenType.LEQ || this.token.getTokenType() == TokenType.GRE || this.token.getTokenType() == TokenType.GEQ) {
            signs.add(this.token.getTokenType());
            this.tokenStream.move();
            addExps.add(parseAddExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        return new RelExp(addExps, signs);
    }

    public GetCharStmt parseGetCharStmt() {
        Lval lval;
        lval = parseLval();
        this.tokenStream.move();
        this.tokenStream.move();
        this.tokenStream.move();
        expect(TokenType.RPARENT);
        expect(TokenType.SEMICN);
        return new GetCharStmt(lval);
    }

    public GetIntStmt parseGetIntStmt() {
        Lval lval;
        lval = parseLval();
        this.tokenStream.move();
        this.tokenStream.move();
        this.tokenStream.move();
        expect(TokenType.RPARENT);
        expect(TokenType.SEMICN);
        return new GetIntStmt(lval);
    }

    public IfStmt parseIfStmt() {
        Cond cond;
        Stmt ifStmt, elseStmt = null;
        this.tokenStream.move();
        this.tokenStream.move();
        cond = parseCond();
        expect(TokenType.RPARENT);
        this.tokenStream.move();
        ifStmt = parseStmt();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (this.token.getTokenType() == TokenType.ELSETK) {
            this.tokenStream.move();
            elseStmt = parseStmt();
        } else {
            this.tokenStream.back(1);
        }
        return new IfStmt(cond, ifStmt, elseStmt);
    }

    public PrintfStmt parsePrintfStmt() {
        String stringConst;
        ArrayList<Exp> exps = new ArrayList<>();
        this.tokenStream.move();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        stringConst = String.valueOf(this.token.getContent());
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        while (this.token.getTokenType() == TokenType.COMMA) {
            this.tokenStream.move();
            exps.add(parseExp());
            this.tokenStream.move();
            this.token = this.tokenStream.getToken();
        }
        this.tokenStream.back(1);
        expect(TokenType.RPARENT);
        expect(TokenType.SEMICN);
        return new PrintfStmt(stringConst, exps);
    }

    public ReturnStmt parseReturnStmt() {
        Exp exp = null;
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (Exp.FIRST.contains(this.token.getTokenType())) {
            exp = parseExp();
        } else {
            this.tokenStream.back(1);
        }
        expect(TokenType.SEMICN);
        return new ReturnStmt(exp);
    }

    public MainFuncDef parseMainFuncDef() {
        Block block;
        this.tokenStream.move();
        this.tokenStream.move();
        expect(TokenType.RPARENT);
        this.tokenStream.move();
        block = parseBlock();
        return new MainFuncDef(block);
    }

    public void expect(TokenType tokenType) {
        int errLineNum;
        this.token = this.tokenStream.getToken();
        errLineNum = this.token.getLineNum();
        this.tokenStream.move();
        this.token = this.tokenStream.getToken();
        if (this.token.getTokenType() != tokenType) {
            switch (tokenType) {
                case SEMICN -> this.errorList.addError(errLineNum, "i");
                case RPARENT -> this.errorList.addError(errLineNum, "j");
                case RBRACK -> this.errorList.addError(errLineNum, "k");
            }
            this.tokenStream.back(1);
        }
    }
}
