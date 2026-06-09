package frontend;

import error.Error;
import error.ErrorSave;
import token.TokenCode;
import token.Token;
import tree.*;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Syntax {
    private ArrayList<Token> tokens = new ArrayList<>();
    private Lexer lexer;
    private FileWriter fileWriter;
    private FileWriter errorFileWriter;
    private Token nowToken;
    private int pos = -1;


    public Syntax(Lexer lexer,FileWriter fileWriter,FileWriter errorFileWriter) {
        this.lexer = lexer;
        this.fileWriter = fileWriter;
        this.errorFileWriter = errorFileWriter;
    }

    public Token getNextToken() {
        pos++;
        if (pos < tokens.size()) {
            nowToken = tokens.get(pos);
            return nowToken;
        }
        while (true) {
            Token token = lexer.nextToken();
            nowToken = token;
            tokens.add(token);
            break;
        }
        return nowToken;
    }

    public Token getBack(int back) {
        pos -= back;
        nowToken = tokens.get(pos);
        return nowToken;
    }

    public CompUnit parseCompUnit() {
        CompUnit compUnit = new CompUnit();
        MainFuncDef mainFuncDef;
        getNextToken();
        while (true) {
            Token token1 = getNextToken();
            Token token2 = getNextToken();
            getBack(2);
            if (token1.getTokenCode() == TokenCode.MAINTK || token2.getTokenCode() == TokenCode.LPARENT) {
                break;
            }
            compUnit.addDecl(parseDecl());
        }
        while (true) {
            if (getNextToken().getTokenCode() == TokenCode.MAINTK) {
                getBack(1);
                break;
            }
            getBack(1);
            compUnit.addFuncDef(parseFuncDef());
        }
        mainFuncDef = parseMainFuncDef();
        compUnit.setMainFuncDef(mainFuncDef);
        return compUnit;
    }

    public Decl parseDecl() {
        Decl decl = new Decl();
        if (nowToken.getTokenCode() == TokenCode.CONSTTK) {
            decl.setConstDecl(parseConstDecl());
        } else {
            decl.setVarDecl(parseVarDecl());
        }
        return decl;
    }

    public FuncDef parseFuncDef() {
        FuncDef funcDef = new FuncDef();
        funcDef.setFuncType(parseFuncType());
        funcDef.setIdentifier(parseIdentifier());
        funcDef.setLeftB(parseLeftParent());
        if (nowToken != null && nowToken.getTokenCode() != TokenCode.RPARENT && nowToken.getTokenCode() != TokenCode.LBRACE) {
            while (true) {
                funcDef.addFuncFPram(parseFuncFParam());
                if (nowToken.getTokenCode() != TokenCode.COMMA) {
                    funcDef.setRightB(parseRightParent());
                    break;
                } else { getNextToken(); }
            }
        } else {
            funcDef.setRightB(parseRightParent());
        }
        funcDef.setBlock(parseBlock());
        return funcDef;
    }

    public MainFuncDef parseMainFuncDef() {
        MainFuncDef mainFuncDef = new MainFuncDef();
        if (nowToken.getTokenCode() == TokenCode.INTTK) {
            mainFuncDef.setIntTk(nowToken);
            if (getNextToken().getTokenCode() == TokenCode.MAINTK) {
                mainFuncDef.setMain(nowToken);
                getNextToken();
            } else {
                System.out.println("unexpected wrong");
                return null;
            }
            mainFuncDef.setLeftB(parseLeftParent());
            mainFuncDef.setRightB(parseRightParent());
            mainFuncDef.setBlock(parseBlock());
            return mainFuncDef;
        } else {
            System.out.println("unexpected wrong");
            return null;
        }
    }

    public ConstDecl parseConstDecl() {
        ConstDecl constDecl = new ConstDecl();
        constDecl.setCon(parseConst());
        constDecl.setBType(parseBtype());
        while (true) {
            constDecl.addConstDef(parseConstDef());
            if (nowToken.getTokenCode() != TokenCode.COMMA) {
                constDecl.setSemicn(parseSemicn());
                 break;
            } else {
                getNextToken();
            }
        }
        return constDecl;
    }

    public VarDecl parseVarDecl() {
        VarDecl varDecl = new VarDecl();
        varDecl.setBType(parseBtype());
        while (true) {
            varDecl.addVarDef(parseVarDef());
            if (nowToken.getTokenCode() != TokenCode.COMMA) {
                varDecl.setSemicn(parseSemicn());
                break;
            } else {
                getNextToken();
            }
        }
        return varDecl;
    }

    public FuncType parseFuncType() {
        Token re = nowToken;
        getNextToken();
        FuncType funcType = new FuncType();
        funcType.setType(re);
        return funcType;
    }

    public Token parseIdentifier() {
        Token re = nowToken;
        getNextToken();
        return re;
    }

    public Token parseLeftParent() {
        Token re = nowToken;
        getNextToken();
        return re;
    }

    public FuncFParam parseFuncFParam() {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.setbType(parseBtype());
        funcFParam.setIdentifier(parseIdentifier());
        if (nowToken.getTokenCode() == TokenCode.LBRACK) {
            funcFParam.setDimension(1);
            funcFParam.setLeftB(parseLeftBrack());
            funcFParam.setRightB(parseRightBrack());
        } else {
            funcFParam.setDimension(0);
        }
        return funcFParam;
    }

    public Token parseRightParent() {
        //需要处理错误
        if (nowToken == null || nowToken.getTokenCode() != TokenCode.RPARENT) {
            Token token = getBack(1);
            ErrorSave.getErrors().add(new Error(token.getLine(),"j","lackRightParent"));
            getNextToken();
            return new Token(token.getLine(),")",TokenCode.RPARENT);
        } else {
            Token re = nowToken;
            getNextToken();
            return re;
        }
    }

    public Block parseBlock() {
        Block block = new Block();
        block.setLeftB(parseLeftBrace());
        while (true) {
            if (nowToken != null && nowToken.getTokenCode() != TokenCode.RBRACE) {
                block.addBlockItem(parseBlockItem());
            } else {
                block.setRightB(parseRightBrace());
                break;
            }
        }
        return block;
    }

    public Token parseLeftBrace() {
        Token re = nowToken;
        getNextToken();
        return re;
    }

    public Token parseRightBrace() {
        Token re = nowToken;
        getNextToken();
        return re;
    }

    public Token parseConst() {
        Token re = nowToken;
        getNextToken();
        return re;
    }

    public BType parseBtype() {
        BType bType = new BType();
        Token re = nowToken;
        getNextToken();
        bType.setTypeToken(re);
        return bType;
    }

    public ConstDef parseConstDef() {
        ConstDef constDef = new ConstDef();
        constDef.setIdentifier(parseIdentifier());
        if (nowToken.getTokenCode() == TokenCode.LBRACK) {
            constDef.setLeftB(parseLeftBrack());
            constDef.setConstExp(parseConstExp());
            constDef.setRightB(parseRightBrack());
        }
        constDef.setEqTk(parseEqualTk());
        constDef.setConstInitVal(parseConstInitVal());
        return constDef;
    }

    public Token parseSemicn() {
        //需要错误处理
        if (nowToken == null || nowToken.getTokenCode() != TokenCode.SEMICN) {
            Token token = getBack(1);
            ErrorSave.getErrors().add(new Error(token.getLine(),"i","lackSemicn"));
            getNextToken();
            return new Token(token.getLine(),";",TokenCode.SEMICN);
        } else {
            Token re = nowToken;
            getNextToken();
            return re;
        }
    }

    public VarDef parseVarDef() {
        VarDef varDef = new VarDef();
        varDef.setIdentifier(parseIdentifier());
        if (nowToken.getTokenCode() == TokenCode.LBRACK) {
            varDef.setLeftB(parseLeftBrack());
            varDef.setConstExp(parseConstExp());
            varDef.setRightB(parseRightBrack());
        }
        if (nowToken.getTokenCode() == TokenCode.ASSIGN) {
            varDef.setEqualTk(parseEqualTk());
            varDef.setInitVal(parseInitVal());
        }
        return varDef;
    }

    public Token parseLeftBrack() {
        Token re = nowToken;
        getNextToken();
        return re;
    }

    public ConstExp parseConstExp() {
        ConstExp constExp = new ConstExp();
        constExp.setAddExp(parseAddExp());
        return constExp;
    }

    public Token parseRightBrack() {
        //需要错误处理
        if (nowToken == null || nowToken.getTokenCode() != TokenCode.RBRACK) {
            Token token = getBack(1);
            ErrorSave.getErrors().add(new Error(token.getLine(),"k","lackRightBrack"));
            getNextToken();
            return new Token(token.getLine(),"]",TokenCode.RBRACK);
        } else {
            Token re = nowToken;
            getNextToken();
            return re;
        }
    }

    public BlockItem parseBlockItem() {
        BlockItem blockItem = new BlockItem();
        if (nowToken.getTokenCode() == TokenCode.CONSTTK ||
            nowToken.getTokenCode() == TokenCode.INTTK ||
            nowToken.getTokenCode() == TokenCode.VOIDTK ||
            nowToken.getTokenCode() == TokenCode.CHARTK) {
            blockItem.setDecl(parseDecl());
        } else {
            blockItem.setStmt(parseStmt());
        }
        return blockItem;
    }

    public Token parseEqualTk() {
        Token re = nowToken;
        getNextToken();
        return re;
    }

    public ConstInitVal parseConstInitVal() {
        ConstInitVal constInitVal = new ConstInitVal();
        if (nowToken.getTokenCode() == TokenCode.LBRACE) {
            constInitVal.setLeftB(parseLeftBrace());
            if (nowToken.getTokenCode() != TokenCode.RBRACE) {
                constInitVal.addConstExp(parseConstExp());
            }
            while (true) {
                if (nowToken.getTokenCode() != TokenCode.COMMA) {
                    constInitVal.setRightB(parseRightBrace());
                    break;
                } else {
                    getNextToken();
                }
                constInitVal.addConstExp(parseConstExp());
            }
        } else if (nowToken.getTokenCode() == TokenCode.STRCON) {
            constInitVal.setStringConst(parseStringConst());
        } else {
            constInitVal.addConstExp(parseConstExp());
        }
        return constInitVal;
    }

    public InitVal parseInitVal() {
        InitVal initVal = new InitVal();
        if (nowToken.getTokenCode() == TokenCode.LBRACE) {
            initVal.setLeftB(parseLeftBrace());
            if (nowToken.getTokenCode() != TokenCode.RBRACE) {
                initVal.addExp(parseExp());
            }
            while (true) {
                if (nowToken.getTokenCode() != TokenCode.COMMA) {
                    initVal.setRightB(parseRightBrace());
                    break;
                } else {
                    getNextToken();
                }
                initVal.addExp(parseExp());
            }
        } else if (nowToken.getTokenCode() == TokenCode.STRCON) {
            initVal.setStringConst(parseStringConst());
        } else {
            initVal.addExp(parseExp());
        }
        return initVal;
    }

    public AddExp parseAddExp() {
        AddExp addExp = new AddExp();
        addExp.setMulExp(parseMulExp());
        if (nowToken.getTokenCode() == TokenCode.PLUS ||
                nowToken.getTokenCode() == TokenCode.MINU) {
            addExp.setSign(nowToken);
            getNextToken();
            addExp.setAddExp(parseAddExp());
        }
        return addExp;
    }

    public Stmt parseStmt() {
        Stmt stmt = new Stmt();
        if (nowToken.getTokenCode() == TokenCode.PRINTFTK) {
            stmt.setType(1);    // 'printf''('StringConst {','Exp}')'';'
            stmt.setPrintfTk(nowToken);
            getNextToken();
            stmt.setLeftB(parseLeftParent());
            stmt.setStringConst(parseStringConst());
            while (true) {
                if (nowToken.getTokenCode() != TokenCode.COMMA) {
                    stmt.setRightB(parseRightParent());
                    break;
                } else {
                    getNextToken();
                }
                stmt.addExp(parseExp());
            }
            stmt.setSemicn(parseSemicn());
        } else if (nowToken.getTokenCode() == TokenCode.RETURNTK) {
            stmt.setType(2);    //  'return' [Exp] ';'
            stmt.setReturnTk(nowToken);
            getNextToken();
            if (nowToken.getTokenCode() == TokenCode.IDENFR || nowToken.getTokenCode() == TokenCode.PLUS || nowToken.getTokenCode() == TokenCode.MINU
                    || nowToken.getTokenCode() == TokenCode.LPARENT || nowToken.getTokenCode() == TokenCode.INTCON || nowToken.getTokenCode() == TokenCode.CHRCON || nowToken.getTokenCode() == TokenCode.NOT) {
                stmt.setExp(parseExp());
                stmt.setSemicn(parseSemicn());
            } else {
                stmt.setSemicn(parseSemicn());
            }
        } else if (nowToken.getTokenCode() == TokenCode.CONTINUETK ||
                    nowToken.getTokenCode() == TokenCode.BREAKTK) {
            stmt.setType(3);    //  'break' ';' | 'continue' ';'
            if (nowToken.getTokenCode() == TokenCode.BREAKTK)
                stmt.setBreakTk(nowToken);
            else
                stmt.setContinueTk(nowToken);
            getNextToken();
            stmt.setSemicn(parseSemicn());
        } else if (nowToken.getTokenCode() == TokenCode.FORTK) {
            stmt.setType(4); // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            stmt.setForTk(nowToken);
            getNextToken();
            stmt.setLeftB(parseLeftParent());
            if (nowToken != null && nowToken.getTokenCode() == TokenCode.IDENFR) {
                stmt.setForStmt1(parseForStmt());
            }
            stmt.setSemicn(parseSemicn());
            if (nowToken != null && nowToken.getTokenCode() != TokenCode.SEMICN) {
                 stmt.setCond(parseCond());
            }
            stmt.setSemicn(parseSemicn());
            if (nowToken != null && nowToken.getTokenCode() != TokenCode.RPARENT) {
                stmt.setForStmt2(parseForStmt());
            }
            stmt.setRightB(parseRightParent());
            stmt.setStmtFor(parseStmt());
        } else if (nowToken.getTokenCode() == TokenCode.IFTK) {
            stmt.setType(5); // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            stmt.setIfTk(nowToken);
            getNextToken();
            stmt.setLeftB(parseLeftParent());
            stmt.setCond(parseCond());
            stmt.setRightB(parseRightParent());
            stmt.setStmtIf(parseStmt());
            if (nowToken.getTokenCode() == TokenCode.ELSETK) {
                stmt.setElseTk(nowToken);
                getNextToken();
                stmt.setStmtElse(parseStmt());
            }
        } else if (nowToken.getTokenCode() == TokenCode.LBRACE) {
            stmt.setType(6); // Block
            stmt.setBlock(parseBlock());
        } else if (nowToken.getTokenCode() == TokenCode.IDENFR) {
            int rePos = pos;
            ArrayList<Error> recordError = new ArrayList<>(ErrorSave.getErrors());
            LVal lVal = parseLVal();
            if (nowToken.getTokenCode() == TokenCode.ASSIGN) {
                stmt.setlVal(lVal);
                dealLValStmt(stmt);
            } else {
                getBack(pos - rePos);
                dealExpStmt(stmt,recordError);
            }
        } else {
            dealExpStmt(stmt,null);
        }
        return stmt;
    }

    public void dealLValStmt(Stmt stmt) {
        stmt.setEqualTk(parseEqualTk());
        if (nowToken.getTokenCode() == TokenCode.GETINTTK || nowToken.getTokenCode() == TokenCode.GETCHARTK) {
            if (nowToken.getTokenCode() == TokenCode.GETINTTK) {
                stmt.setType(7); // LVal '=' 'getint''('')'';
                stmt.setGetintTk(nowToken);
            } else {
                stmt.setType(8); //LVal '=' 'getchar''('')'';
                stmt.setGetCharTk(nowToken);
            }
            getNextToken();
            stmt.setLeftB(parseLeftParent());
            stmt.setRightB(parseRightParent());
            stmt.setSemicn(parseSemicn());
        } else {
            stmt.setType(9);
            stmt.setExp(parseExp());
            stmt.setSemicn(parseSemicn());
        }
    }

    public void dealExpStmt(Stmt stmt,ArrayList<Error> errors) {
        if (errors != null)
            ErrorSave.setErrors(errors);
        stmt.setType(10);
        if (nowToken != null && nowToken.getTokenCode() != TokenCode.SEMICN)
            stmt.setExp(parseExp());
        stmt.setSemicn(parseSemicn());
    }

    public StringConst parseStringConst() {
        Token re = nowToken;
        getNextToken();
        StringConst stringConst = new StringConst();
        stringConst.setString(re);
        return stringConst;
    }

    public Exp parseExp() {
        Exp exp = new Exp();
        exp.setAddExp(parseAddExp());
        return exp;
    }

    public MulExp parseMulExp() {
        MulExp mulExp = new MulExp();
        mulExp.setUnaryExp(parseUnaryExp());
        if (nowToken.getTokenCode() == TokenCode.MULT ||
                nowToken.getTokenCode() == TokenCode.DIV ||
                nowToken.getTokenCode() == TokenCode.MOD) {
            mulExp.setSign(nowToken);
            getNextToken();
            mulExp.setMulExp(parseMulExp());
        }
        return mulExp;
    }

    public ForStmt parseForStmt() {
        ForStmt forStmt = new ForStmt();
        forStmt.setlVal(parseLVal());
        forStmt.setEqualTk(nowToken);
        getNextToken();
        forStmt.setExp(parseExp());
        return forStmt;
    }

    public Cond parseCond() {
        Cond cond = new Cond();
        cond.setlOrExp(parseLOrExp());
        return cond;
    }

    public LVal parseLVal() {
        LVal lVal = new LVal();
        lVal.setIdentifier(parseIdentifier());
        if (nowToken.getTokenCode() == TokenCode.LBRACK) {
            lVal.setDimension(1);
            lVal.setLeftB(parseLeftBrack());
            lVal.setExp(parseExp());
            lVal.setRightB(parseRightBrack());
        } else { lVal.setDimension(0); }
        return lVal;
    }

    public UnaryExp parseUnaryExp() {
        UnaryExp unaryExp = new UnaryExp();
        Token token = getNextToken();
        getBack(1);
        if (nowToken.getTokenCode() == TokenCode.PLUS ||
                nowToken.getTokenCode() == TokenCode.MINU ||
                 nowToken.getTokenCode() == TokenCode.NOT) {
            unaryExp.setUnaryOp(parseUnaryOp());
            unaryExp.setUnaryExp(parseUnaryExp());
        } else if (nowToken.getTokenCode() == TokenCode.IDENFR &&
                   token.getTokenCode() == TokenCode.LPARENT) {
            unaryExp.setIdentifier(parseIdentifier());
            unaryExp.setLeftB(parseLeftParent());
            if (nowToken.getTokenCode() == TokenCode.IDENFR || nowToken.getTokenCode() == TokenCode.PLUS || nowToken.getTokenCode() == TokenCode.MINU
                    || nowToken.getTokenCode() == TokenCode.LPARENT || nowToken.getTokenCode() == TokenCode.INTCON || nowToken.getTokenCode() == TokenCode.CHRCON || nowToken.getTokenCode() == TokenCode.NOT) {
                while (true) {
                    unaryExp.addFuncRParam(parseExp());
                    if (nowToken.getTokenCode() != TokenCode.COMMA) {
                        unaryExp.setRightB(parseRightParent());
                        break;
                    } else { getNextToken(); }
                }
            } else {
                unaryExp.setRightB(parseRightParent());
            }
        } else {
            unaryExp.setPrimaryExp(parsePrimaryExp());
        }
        return unaryExp;
    }

    public LOrExp parseLOrExp() {
        LOrExp lOrExp = new LOrExp();
        lOrExp.setlAndExp(parseLAndExp());
        if (nowToken.getTokenCode() == TokenCode.OR) {
            lOrExp.setOr(nowToken);
            getNextToken();
            lOrExp.setlOrExp(parseLOrExp());
        }
        return lOrExp;
    }

    public UnaryOp parseUnaryOp() {
        UnaryOp unaryOp = new UnaryOp();
        unaryOp.setSign(nowToken);
        getNextToken();
        return unaryOp;
    }

    public PrimaryExp parsePrimaryExp() {
        PrimaryExp primaryExp = new PrimaryExp();
        if (nowToken.getTokenCode() == TokenCode.LPARENT) {
            primaryExp.setLeftB(parseLeftParent());
            primaryExp.setExp(parseExp());
            primaryExp.setRightB(parseRightParent());
        } else if (nowToken.getTokenCode() == TokenCode.IDENFR) {
            primaryExp.setlVal(parseLVal());
        } else if (nowToken.getTokenCode() == TokenCode.INTCON) {
            primaryExp.setNumber(nowToken);
            getNextToken();
        } else {
            primaryExp.setCharacter(nowToken);
            getNextToken();
        }
        return primaryExp;
    }

    public LAndExp parseLAndExp() {
        LAndExp lAndExp = new LAndExp();
        lAndExp.setEqExp(parseEqExp());
        if (nowToken.getTokenCode() == TokenCode.AND) {
            lAndExp.setAnd(nowToken);
            getNextToken();
            lAndExp.setlAndExp(parseLAndExp());
        }
        return lAndExp;
    }

    public EqExp parseEqExp() {
        EqExp eqExp = new EqExp();
        eqExp.setRelExp(parseRelExp());
        if (nowToken.getTokenCode() == TokenCode.EQL || nowToken.getTokenCode() == TokenCode.NEQ) {
            eqExp.setSign(nowToken);
            getNextToken();
            eqExp.setEqExp(parseEqExp());
        }
        return eqExp;
    }

    public RelExp parseRelExp() {
        RelExp relExp = new RelExp();
        relExp.setAddExp(parseAddExp());
        if (nowToken.getTokenCode() == TokenCode.GRE || nowToken.getTokenCode() == TokenCode.GEQ ||
                nowToken.getTokenCode() == TokenCode.LSS || nowToken.getTokenCode() == TokenCode.LEQ) {
            relExp.setSign(nowToken);
            getNextToken();
            relExp.setRelExp(parseRelExp());
        }
        return relExp;
    }

    public void parseAndOutput() throws IOException {
        CompUnit compUnit = parseCompUnit();
        if (ErrorSave.getErrors().isEmpty()) {
            compUnit.output(fileWriter);
        } else {
            for (Error error : ErrorSave.getErrors()) {
                errorFileWriter.write(error.toString() + "\n");
            }
        }
    }

}
