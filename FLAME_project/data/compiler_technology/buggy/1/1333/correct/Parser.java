import lexer.Token;
import lexer.TokenType;
import parser.CompUnit;
import parser.block.*;
import parser.constdecl.*;
import parser.exp.Character;
import parser.exp.Number;
import parser.exp.*;
import parser.func.*;
import parser.vardecl.*;

import java.util.ArrayList;

public class Parser {
    private final ArrayList<Token> tokens;
    private int pos;
    private final CompUnit compUnit;

    public Parser(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.pos = 0;
        this.compUnit = new CompUnit();
        while (this.pos < tokens.size()) {
            if (this.tokens.get(this.pos).getType() == TokenType.CONST) {
                this.compUnit.addDecl(parseConstDecl());
            } else if (this.tokens.get(this.pos + 1).getType() == TokenType.MAIN) {
                this.compUnit.setMainFuncDef(parseMainFuncDef());
            } else if (this.tokens.get(this.pos + 2).getType() == TokenType.LPARENT) {
                this.compUnit.addFuncDef(parseFuncDef());
            } else {
                this.compUnit.addDecl(parseVarDecl());
            }
        }
    }

    public ConstDecl parseConstDecl() {
        this.pos++;
        ConstDecl constDecl = new ConstDecl(this.tokens.get(this.pos));
        this.pos++;
        constDecl.addConstDef(parseConstDef());
        while (this.tokens.get(this.pos).getType() == TokenType.COMMA) {
            this.pos++;
            constDecl.addConstDef(parseConstDef());
        }
        judgeErrorI();
        return constDecl;
    }

    public ConstDef parseConstDef() {
        String ident = this.tokens.get(this.pos).getName();
        this.pos++;
        String now = this.tokens.get(this.pos).getName();
        this.pos++;
        if (now.equals("=")) {
            return new ConstDef(ident, null, parseConstInitVal());
        } else {
            ConstExp constExp = parseConstExp();
            judgeErrorK();
            this.pos++;
            return new ConstDef(ident, constExp, parseConstInitVal());
        }
    }

    public ConstInitVal parseConstInitVal() {
        TokenType type = this.tokens.get(this.pos).getType();
        if (type == TokenType.STRING_CONST) {
            ConstInitVal constInitVal = new ConstInitVal(3, this.tokens.get(this.pos).getName());
            this.pos++;
            return constInitVal;
        } else if (type == TokenType.LBRACE) {
            ConstInitVal constInitVal = new ConstInitVal(2);
            this.pos++;
            if (this.tokens.get(this.pos).getType() != TokenType.RBRACE) {
                constInitVal.addConstExp(parseConstExp());
                while (this.pos < tokens.size()) {
                    if (this.tokens.get(this.pos).getType() != TokenType.COMMA) {
                        break;
                    }
                    this.pos++;
                    constInitVal.addConstExp(parseConstExp());
                }
            }
            this.pos++;
            return constInitVal;
        } else {
            ConstInitVal constInitVal = new ConstInitVal(1);
            constInitVal.addConstExp(parseConstExp());
            return constInitVal;
        }
    }

    public ConstExp parseConstExp() {
        AddExp addExp = parseAddExp();
        return new ConstExp(addExp);
    }

    public AddExp parseAddExp() {
        AddExp addExp = new AddExp(parseMulExp());
        while (this.pos < tokens.size()) {
            Token now = this.tokens.get(this.pos);
            if (now.getType() != TokenType.PLUS && now.getType() != TokenType.MINU) {
                break;
            }
            addExp.addOp(now);
            this.pos++;
            addExp.addMulExp(parseMulExp());
        }
        return addExp;
    }

    public MulExp parseMulExp() {
        MulExp mulExp = new MulExp(parseUnaryExp());
        while (this.pos < tokens.size()) {
            Token now = this.tokens.get(this.pos);
            if (now.getType() != TokenType.MULT
                    && now.getType() != TokenType.DIV && now.getType() != TokenType.MOD) {
                break;
            }
            mulExp.addOp(now);
            this.pos++;
            mulExp.addUnaryExp(parseUnaryExp());
        }
        return mulExp;
    }

    public UnaryExp parseUnaryExp() {
        UnaryExp unaryExp = new UnaryExp();
        while (this.pos < tokens.size()) {
            Token now = this.tokens.get(this.pos);
            if (now.getType() == TokenType.PLUS ||
                    now.getType() == TokenType.MINU || now.getType() == TokenType.NOT) {
                unaryExp.addOp(now);
                this.pos++;
            } else {
                break;
            }
        }
        if (this.tokens.get(this.pos).getType() == TokenType.IDENT
                && this.tokens.get(this.pos + 1).getType() == TokenType.LPARENT) {
            unaryExp.setSimpleUnaryExp(parseFuncExp());
        } else {
            unaryExp.setSimpleUnaryExp(parsePrimaryExp());
        }
        return unaryExp;
    }

    public PrimaryExp parsePrimaryExp() {
        Token now = this.tokens.get(this.pos);
        if (now.getType() == TokenType.LPARENT) {
            this.pos++;
            Exp exp = parseExp(true);
            judgeErrorJ();
            return new PrimaryExp(exp);
        } else if (now.getType() == TokenType.INT_CONST) {
            return new PrimaryExp(parseNumber());
        } else if (now.getType() == TokenType.CHAR_CONST) {
            return new PrimaryExp(parseCharacter());
        } else {
            return new PrimaryExp(parseLVal());
        }
    }

    public Exp parseExp(boolean hasParent) {
        AddExp addExp = parseAddExp();
        return new Exp(addExp, hasParent);
    }

    public Number parseNumber() {
        this.pos++;
        return new Number(this.tokens.get(this.pos - 1).getName());
    }

    public Character parseCharacter() {
        this.pos++;
        return new Character(this.tokens.get(this.pos - 1).getName());
    }

    public LVal parseLVal() {
        String ident = this.tokens.get(this.pos).getName();
        this.pos++;
        if (this.tokens.get(this.pos).getType() == TokenType.LBRACK) {
            this.pos++;
            Exp exp = parseExp(false);
            judgeErrorK();
            return new LVal(ident, exp);
        } else {
            return new LVal(ident, null);
        }
    }

    public FuncExp parseFuncExp() {
        String ident = this.tokens.get(this.pos).getName();
        this.pos++;
        this.pos++;
        FuncRParams funcRParams = new FuncRParams();
        if (this.tokens.get(this.pos).getType() == TokenType.RPARENT) {
            this.pos++;
            return new FuncExp(ident, null);
        }
        TokenType n = this.tokens.get(this.pos).getType();
        if (n == TokenType.IDENT || n == TokenType.INT_CONST
                || n == TokenType.CHAR_CONST || n == TokenType.LPARENT
                || n == TokenType.PLUS || n == TokenType.MINU) {
            while (this.pos < tokens.size()) {
                funcRParams.addExp(parseExp(false));
                if (this.tokens.get(this.pos).getType() != TokenType.COMMA) {
                    break;
                }
                this.pos++;
            }
        }
        judgeErrorJ();
        return new FuncExp(ident, funcRParams);
    }

    public VarDecl parseVarDecl() {
        VarDecl varDecl = new VarDecl(this.tokens.get(this.pos));
        this.pos++;
        varDecl.addVarDef(parseVarDef());
        while (this.tokens.get(this.pos).getType() == TokenType.COMMA) {
            this.pos++;
            varDecl.addVarDef(parseVarDef());
        }
        judgeErrorI();
        return varDecl;
    }

    public VarDef parseVarDef() {
        VarDef varDef = new VarDef(this.tokens.get(this.pos).getName());
        this.pos++;
        String now = this.tokens.get(this.pos).getName();
        if (now.equals("[")) {
            this.pos++;
            varDef.setConstExp(parseConstExp());
            judgeErrorK();
            now = this.tokens.get(this.pos).getName();
        }
        if (now.equals("=")) {
            this.pos++;
            varDef.setInitVal(parseInitVal());
        }
        return varDef;
    }

    public InitVal parseInitVal() {
        TokenType type = this.tokens.get(this.pos).getType();
        if (type == TokenType.STRING_CONST) {
            InitVal initVal = new InitVal(3, this.tokens.get(this.pos).getName());
            this.pos++;
            return initVal;
        } else if (type == TokenType.LBRACE) {
            InitVal initVal = new InitVal(2);
            this.pos++;
            if (this.tokens.get(this.pos).getType() != TokenType.RBRACE) {
                initVal.addExp(parseExp(false));
                while (this.pos < tokens.size()) {
                    if (this.tokens.get(this.pos).getType() != TokenType.COMMA) {
                        break;
                    }
                    this.pos++;
                    initVal.addExp(parseExp(false));
                }
            }
            this.pos++;
            return initVal;
        } else {
            InitVal initVal = new InitVal(1);
            initVal.addExp(parseExp(false));
            return initVal;
        }
    }

    public FuncDef parseFuncDef() {
        FuncType funcType = new FuncType(this.tokens.get(this.pos));
        this.pos++;
        String ident = this.tokens.get(this.pos).getName();
        this.pos++;
        this.pos++;
        FuncFParams funcFParams = new FuncFParams();
        TokenType now = this.tokens.get(this.pos).getType();
        if (now == TokenType.RPARENT) {
            funcFParams = null;
        } else if (now == TokenType.INT || now == TokenType.CHAR){
            while (this.pos < tokens.size()) {
                funcFParams.addFuncFParam(parseFuncFParam());
                if (this.tokens.get(this.pos).getType() != TokenType.COMMA) {
                    break;
                }
                this.pos++;
            }
        }
        judgeErrorJ();
        return new FuncDef(funcType, ident, funcFParams, parseBlock());
    }

    public FuncFParam parseFuncFParam() {
        Token bType = this.tokens.get(this.pos);
        this.pos++;
        String ident = this.tokens.get(this.pos).getName();
        this.pos++;
        if (this.tokens.get(this.pos).getType() == TokenType.LBRACK) {
            this.pos++;
            judgeErrorK();
            return new FuncFParam(bType, ident, true);
        } else {
            return new FuncFParam(bType, ident, false);
        }
    }

    public MainFuncDef parseMainFuncDef() {
        this.pos += 3;
        judgeErrorJ();
        return new MainFuncDef(parseBlock());
    }

    public Block parseBlock() {
        Block block = new Block();
        this.pos++;
        while (this.tokens.get(this.pos).getType() != TokenType.RBRACE) {
            Token now = this.tokens.get(this.pos);
            if (now.getType() == TokenType.CONST) {
                block.addBlockItem(parseConstDecl());
            } else if (now.getType() == TokenType.INT
                    || now.getType() == TokenType.CHAR) {
                block.addBlockItem(parseVarDecl());
            } else {
                block.addBlockItem(parseStmt());
            }
        }
        this.pos++;
        return block;
    }

    public Stmt parseStmt() {
        TokenType now = this.tokens.get(this.pos).getType();
        if (now == TokenType.BREAK) {
            this.pos++;
            judgeErrorI();
            return new BreakStmt();
        } else if (now == TokenType.CONTINUE) {
            this.pos++;
            judgeErrorI();
            return new ContinueStmt();
        } else if (now == TokenType.RETURN) {
            this.pos++;
            TokenType n = this.tokens.get(this.pos).getType();
            if (n == TokenType.SEMICN) {
                this.pos++;
                return new ReturnStmt(null);
            } else if (n == TokenType.IDENT || n == TokenType.INT_CONST
                    || n == TokenType.CHAR_CONST || n == TokenType.LPARENT
                    || n == TokenType.PLUS || n == TokenType.MINU){
                Exp exp = parseExp(false);
                judgeErrorI();
                return new ReturnStmt(exp);
            } else {
                judgeErrorI();
                return new ReturnStmt(null);
            }
        } else if (now == TokenType.LBRACE) {
            return new BlockStmt(parseBlock());
        } else if (now == TokenType.PRINTF) {
            return parsePrintfStmt();
        } else if (now == TokenType.IF) {
            return parseIfStmt();
        } else if (now == TokenType.FOR) {
            return parseForLoopStmt();
        } else {
            int start = this.pos;
            if (now == TokenType.IDENT) {
                LVal lVal = parseLVal();
                if (this.tokens.get(this.pos).getType() == TokenType.ASSIGN) {
                    return parseLValStmt(lVal);
                }
            }
            this.pos = start;
            return parseExpStmt();
        }
    }

    public ExpStmt parseExpStmt() {
        Exp exp = null;
        if (this.tokens.get(this.pos).getType() != TokenType.SEMICN) {
            exp = parseExp(false);
        }
        judgeErrorI();
        return new ExpStmt(exp);
    }

    public Stmt parseLValStmt(LVal lVal) {
        this.pos++;
        TokenType now = this.tokens.get(this.pos).getType();
        if (now == TokenType.GETINT) {
            this.pos += 2;
            judgeErrorJ();
            judgeErrorI();
            return new GetIntStmt(lVal);
        } else if (now == TokenType.GETCHAR) {
            this.pos += 2;
            judgeErrorJ();
            judgeErrorI();
            return new GetCharStmt(lVal);
        } else {
            Exp exp = parseExp(false);
            judgeErrorI();
            return new LValStmt(lVal, exp);
        }
    }

    public PrintfStmt parsePrintfStmt() {
        this.pos += 2;
        String stringConst = this.tokens.get(this.pos).getName();
        PrintfStmt printfStmt = new PrintfStmt(stringConst);
        this.pos++;
        while (this.tokens.get(this.pos).getType() == TokenType.COMMA) {
            this.pos++;
            printfStmt.addExp(parseExp(false));
        }
        judgeErrorJ();
        judgeErrorI();
        return printfStmt;
    }

    public IfStmt parseIfStmt() {
        this.pos += 2;
        Cond cond = new Cond(parseLOrExp());
        judgeErrorJ();
        Stmt ifStmt = parseStmt();
        if (this.tokens.get(this.pos).getType() == TokenType.ELSE) {
            this.pos++;
            return new IfStmt(cond, ifStmt, parseStmt());
        } else {
            return new IfStmt(cond, ifStmt, null);
        }
    }

    public LOrExp parseLOrExp() {
        LOrExp lOrExp = new LOrExp(parseLAndExp());
        while (this.pos < tokens.size()) {
            Token now = this.tokens.get(this.pos);
            if (now.getType() != TokenType.OR) {
                break;
            }
            this.pos++;
            lOrExp.addLAndExp(parseLAndExp());
        }
        return lOrExp;
    }

    public LAndExp parseLAndExp() {
        LAndExp lAndExp = new LAndExp(parseEqExp());
        while (this.pos < tokens.size()) {
            Token now = this.tokens.get(this.pos);
            if (now.getType() != TokenType.AND) {
                break;
            }
            this.pos++;
            lAndExp.addEqExp(parseEqExp());
        }
        return lAndExp;
    }

    public EqExp parseEqExp() {
        EqExp eqExp = new EqExp(parseRelExp());
        while (this.pos < tokens.size()) {
            Token now = this.tokens.get(this.pos);
            if (now.getType() != TokenType.EQL && now.getType() != TokenType.NEQ) {
                break;
            }
            eqExp.addOp(now);
            this.pos++;
            eqExp.addRelExp(parseRelExp());
        }
        return eqExp;
    }

    public RelExp parseRelExp() {
        RelExp relExp = new RelExp(parseAddExp());
        while (this.pos < tokens.size()) {
            Token now = this.tokens.get(this.pos);
            if (now.getType() != TokenType.GEQ && now.getType() != TokenType.GRE
                    && now.getType() != TokenType.LEQ && now.getType() != TokenType.LSS) {
                break;
            }
            relExp.addOp(now);
            this.pos++;
            relExp.addAddExp(parseAddExp());
        }
        return relExp;
    }

    public ForLoopStmt parseForLoopStmt() {
        ForLoopStmt forLoopStmt = new ForLoopStmt();
        this.pos += 2;
        if (this.tokens.get(this.pos).getType() != TokenType.SEMICN) {
            forLoopStmt.setForStmt1(parseForStmt());
        }
        this.pos++;
        if (this.tokens.get(this.pos).getType() != TokenType.SEMICN) {
            forLoopStmt.setCond(new Cond(parseLOrExp()));
        }
        this.pos++;
        if (this.tokens.get(this.pos).getType() != TokenType.RPARENT) {
            forLoopStmt.setForStmt2(parseForStmt());
        }
        this.pos++;
        forLoopStmt.setStmt(parseStmt());
        return forLoopStmt;
    }

    public ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        this.pos++;
        Exp exp = parseExp(false);
        return new ForStmt(lVal, exp);
    }

    public CompUnit getCompUnit() {
        return this.compUnit;
    }

    public void judgeErrorI() {
        if (this.tokens.get(this.pos).getType() != TokenType.SEMICN) {
            ErrorSet.errorSet.add(new Error(this.tokens.get(this.pos - 1).getPosition(), "i"));
        } else {
            this.pos++;
        }
    }

    public void judgeErrorJ() {
        if (this.tokens.get(this.pos).getType() != TokenType.RPARENT) {
            ErrorSet.errorSet.add(new Error(this.tokens.get(this.pos - 1).getPosition(), "j"));
        } else {
            this.pos++;
        }
    }

    public void judgeErrorK() {
        if (this.tokens.get(this.pos).getType() != TokenType.RBRACK) {
            ErrorSet.errorSet.add(new Error(this.tokens.get(this.pos - 1).getPosition(), "k"));
        } else {
            this.pos++;
        }
    }
}