package frontend;

import java.util.ArrayList;

public class Parser {
    private ArrayList<Word> words = new ArrayList<>();
    private int pos = 0; //指针
    private int jiLu;
    private int sign;
    private int ifRight = 1;
    public Parser(ArrayList<Word> words) {
        this.words = words;
    }

    public int getIfRight() {
        return ifRight;
    }

    public CompUnit parseCompUnit() {
        CompUnit compUnit = new CompUnit();
        while (words.get(pos).getStr().equals("const") ||
            !words.get(pos + 2).getStr().equals("(")) {
            compUnit.addDecl(parseDecl());
        }
        while (!words.get(pos + 1).getStr().equals("main")) {
            compUnit.addFuncDef(parseFuncDef());
        }
        compUnit.setMainFuncDef(parseMainFuncDef());
        return compUnit;
    }

    public MainFuncDef parseMainFuncDef() {
        MainFuncDef mainFuncDef = new MainFuncDef();
        mainFuncDef.addWord(words.get(pos++));
        mainFuncDef.addWord(words.get(pos++));
        mainFuncDef.addWord(words.get(pos++));
        if (words.get(pos).getStr().equals(")")) {
            mainFuncDef.addWord(words.get(pos++));
        } else {
            ifRight = 0;
            mainFuncDef.setWrong();
        }
        mainFuncDef.setBlock(parseBlock());
        return mainFuncDef;
    }

    public FuncDef parseFuncDef() {
        FuncDef funcDef = new FuncDef();
        funcDef.setFuncType(parseFuncType());
        funcDef.addWord(words.get(pos++));
        funcDef.addWord(words.get(pos++));
        if (words.get(pos).getStr().equals(")")) {
            funcDef.addWord(words.get(pos++));
            funcDef.setBlock(parseBlock());
        } else if (words.get(pos).getStr().equals("{")) {
            ifRight = 0;
            funcDef.setWrong();
            funcDef.setBlock(parseBlock());
        } else {
            funcDef.setFuncFParams(parseFuncFParams());
            if (words.get(pos).getStr().equals(")")) {
                funcDef.addWord(words.get(pos++));
                funcDef.setBlock(parseBlock());
            } else {
                ifRight = 0;
                funcDef.setWrong();
                funcDef.setBlock(parseBlock());
            }
        }
        return funcDef;
    }

    public Block parseBlock() {
        Block block = new Block();
        block.addWord(words.get(pos++));
        while (!words.get(pos).getStr().equals("}")) {
            block.addBlockItem(parseBlockItem());
        }
        block.addWord(words.get(pos++));
        return block;
    }

    public BlockItem parseBlockItem() {
        if (words.get(pos).getStr().equals("const") ||
                words.get(pos).getStr().equals("int") ||
                words.get(pos).getStr().equals("char")) {
            return parseDecl();
        } else {
            return parseStmt();
        }
    }

    public Stmt parseStmt() {
        Stmt stmt = new Stmt();
        if (words.get(pos).getStr().equals("{")) {
            stmt.setLeibie(3);
            stmt.setBlock(parseBlock());
        } else if (words.get(pos).getStr().equals("if")) {
            stmt.setLeibie(4);
            stmt.addWord(words.get(pos++));
            stmt.addWord(words.get(pos++));
            stmt.setCond(parseCond());
            if (!words.get(pos).getStr().equals(")")) {
                ifRight = 0;
                stmt.setWrong(2);
            } else {
                stmt.addWord(words.get(pos++));
            }
            stmt.addStmt(parseStmt());
            if (words.get(pos).getStr().equals("else")) {
                stmt.addWord(words.get(pos++));
                stmt.addStmt(parseStmt());
            }
        } else if (words.get(pos).getStr().equals("for")) {
            stmt.setLeibie(5);
            stmt.addWord(words.get(pos++));
            stmt.addWord(words.get(pos++));
            if (!words.get(pos).getStr().equals(";")) {
                stmt.setForStmt1(parseForStmt());
            }
            stmt.addWord(words.get(pos++));
            if (!words.get(pos).getStr().equals(";")) {
                stmt.setCond(parseCond());
            }
            stmt.addWord(words.get(pos++));
            if (!words.get(pos).getStr().equals(")")) {
                stmt.setForStmt2(parseForStmt());
            }
            stmt.addWord(words.get(pos++));
            stmt.addStmt(parseStmt());
        } else if (words.get(pos).getStr().equals("break") ||
                words.get(pos).getStr().equals("continue")) {
            stmt.setLeibie(6);
            stmt.addWord(words.get(pos++));
            if (words.get(pos).getStr().equals(";")) {
                stmt.addWord(words.get(pos++));
            } else {
                ifRight = 0;
                stmt.setWrong(1);
            }
        } else if (words.get(pos).getStr().equals("return")) {
            stmt.setLeibie(7);
            stmt.addWord(words.get(pos++));
            if (words.get(pos).getStr().equals(";")) {
                stmt.addWord(words.get(pos++));
            } else {
                if (notExp()) {
                    ifRight = 0;
                    stmt.setWrong(1);
                } else {
                    stmt.addExp(parseExp());
                    if (words.get(pos).getStr().equals(";")) {
                        stmt.addWord(words.get(pos++));
                    } else {
                        ifRight = 0;
                        stmt.setWrong(1);
                    }
                }
            }
        } else if (words.get(pos).getStr().equals("printf")) {
            stmt.setLeibie(10);
            stmt.addWord(words.get(pos++));
            stmt.addWord(words.get(pos++));
            stmt.addWord(words.get(pos++));
            while (words.get(pos).getStr().equals(",")) {
                stmt.addWord(words.get(pos++));
                stmt.addExp(parseExp());
            }
            if (words.get(pos).getStr().equals(")")) {
                stmt.addWord(words.get(pos++));
            } else {
                ifRight = 0;
                stmt.setWrong(2);
            }
            if (words.get(pos).getStr().equals(";")) {
                stmt.addWord(words.get(pos++));
            } else {
                ifRight = 0;
                stmt.setWrong(1);
            }
        } else {
            jiLu = pos;
            stmt.setLeibie(2);
            if (words.get(pos).getStr().equals(";")) {
                stmt.addWord(words.get(pos++));
            } else {
                stmt.addExp(parseExp());
                if (words.get(pos).getStr().equals("=")) {
                    pos = jiLu;
                    jiLu = -1;
                    stmt.clearExp();
                    stmt.setLval(parseLval());
                    stmt.addWord(words.get(pos++));
                    if (words.get(pos).getStr().equals("getint")) {
                        stmt.setLeibie(8);
                        stmt.addWord(words.get(pos++));
                        stmt.addWord(words.get(pos++));
                        if (words.get(pos).getStr().equals(")")) {
                            stmt.addWord(words.get(pos++));
                        } else {
                            ifRight = 0;
                            stmt.setWrong(2);
                        }
                        if (words.get(pos).getStr().equals(";")) {
                            stmt.addWord(words.get(pos++));
                        } else {
                            ifRight = 0;
                            stmt.setWrong(1);
                        }
                    } else if (words.get(pos).getStr().equals("getchar")) {
                        stmt.setLeibie(9);
                        stmt.addWord(words.get(pos++));
                        stmt.addWord(words.get(pos++));
                        if (words.get(pos).getStr().equals(")")) {
                            stmt.addWord(words.get(pos++));
                        } else {
                            ifRight = 0;
                            stmt.setWrong(2);
                        }
                        if (words.get(pos).getStr().equals(";")) {
                            stmt.addWord(words.get(pos++));
                        } else {
                            ifRight = 0;
                            stmt.setWrong(1);
                        }
                    } else {
                        stmt.setLeibie(1);
                        stmt.addExp(parseExp());
                        if (words.get(pos).getStr().equals(";")) {
                            stmt.addWord(words.get(pos++));
                        } else {
                            ifRight = 0;
                            stmt.setWrong(1);
                        }
                    }
                }
                if (jiLu != -1) {
                    if (words.get(pos).getStr().equals(";")) {
                        stmt.addWord(words.get(pos++));
                    } else {
                        ifRight = 0;
                        stmt.setWrong(1);
                    }
                }
            }
        }
        return stmt;
    }

    private boolean notExp() {
        sign = pos;
        while (words.get(pos).getStr().equals("(")) {
            pos++;
        }
        boolean n = !(words.get(pos).getLeiBie().equals("INTCON") ||
                words.get(pos).getLeiBie().equals("CHRCON") ||
                words.get(pos).getLeiBie().equals("IDENFR") ||
                words.get(pos).getStr().equals("+") ||
                words.get(pos).getStr().equals("-"));
        pos = sign;
        return n;
    }

    public ForStmt parseForStmt() {
        ForStmt forStmt = new ForStmt();
        forStmt.setlVal(parseLval());
        forStmt.setDen(words.get(pos++));
        forStmt.setExp(parseExp());
        return forStmt;
    }

    public Cond parseCond() {
        return new Cond(parseLOrExp());
    }

    public LOrExp parseLOrExp() {
        LOrExp lOrExp = new LOrExp();
        lOrExp.addLAndExp(parseLAndExp());
        while (words.get(pos).getLeiBie().equals("OR")) {
            lOrExp.addWord(words.get(pos++));
            lOrExp.addLAndExp(parseLAndExp());
        }
        return lOrExp;
    }

    public LAndExp parseLAndExp() {
        LAndExp lAndExp = new LAndExp();
        lAndExp.addEqExp(parseEqExp());
        while (words.get(pos).getLeiBie().equals("AND")) {
            lAndExp.addWord(words.get(pos++));
            lAndExp.addEqExp(parseEqExp());
        }
        return lAndExp;
    }

    public EqExp parseEqExp() {
        EqExp eqExp = new EqExp();
        eqExp.addRelExp(parseRelExp());
        while (words.get(pos).getStr().equals("==") ||
                words.get(pos).getStr().equals("!=")) {
            eqExp.addWord(words.get(pos++));
            eqExp.addRelExp(parseRelExp());
        }
        return eqExp;
    }

    public RelExp parseRelExp() {
        RelExp relExp = new RelExp();
        relExp.addAddExp(parseAddExp());
        while (words.get(pos).getStr().equals("<") ||
                words.get(pos).getStr().equals("<=") ||
                words.get(pos).getStr().equals(">") ||
                words.get(pos).getStr().equals(">=")) {
            relExp.addWord(words.get(pos++));
            relExp.addAddExp(parseAddExp());
        }
        return relExp;
    }

    public AddExp parseAddExp() {
        AddExp addExp = new AddExp();
        addExp.addMulExp(parseMulExp());
        while (words.get(pos).getStr().equals("+") ||
                words.get(pos).getStr().equals("-")) {
            addExp.addWord(words.get(pos++));
            addExp.addMulExp(parseMulExp());
        }
        return addExp;
    }

    public MulExp parseMulExp() {
        MulExp mulExp = new MulExp();
        mulExp.addUnaryExp(parseUnaryExp());
        while (words.get(pos).getStr().equals("*") ||
                words.get(pos).getStr().equals("/") ||
                 words.get(pos).getStr().equals("%")) {
            mulExp.addWord(words.get(pos++));
            mulExp.addUnaryExp(parseUnaryExp());
        }
        return mulExp;
    }

    public UnaryExp parseUnaryExp() {
        UnaryExp unaryExp = new UnaryExp();
        if (words.get(pos).getStr().equals("+") ||
                words.get(pos).getStr().equals("-") ||
                words.get(pos).getStr().equals("!")) {
            unaryExp.setLeibie(3);
            unaryExp.setUnaryOp(parseUnaryOp());
            unaryExp.setUnaryExp(parseUnaryExp());
        } else if (words.get(pos).getLeiBie().equals("IDENFR") &&
                    words.get(pos + 1).getStr().equals("(")) {
            unaryExp.setLeibie(2);
            unaryExp.addWord(words.get(pos++));
            unaryExp.addWord(words.get(pos++));
            if (!notExp()) {
                unaryExp.setFuncRParams(parseFuncRParams());
            }
            if (words.get(pos).getStr().equals(")")) {
                unaryExp.addWord(words.get(pos++));
            } else {
                ifRight = 0;
                unaryExp.setWrong();
            }
        } else {
            unaryExp.setLeibie(1);
            unaryExp.setPrimaryExp(parsePrimaryExp());
        }
        return unaryExp;
    }

    public PrimaryExp parsePrimaryExp() {
        PrimaryExp primaryExp = new PrimaryExp();
        if (words.get(pos).getStr().equals("(")) {
            primaryExp.setLeibie(1);
            primaryExp.setZuo(words.get(pos++));
            primaryExp.setExp(parseExp());
            if (words.get(pos).getStr().equals(")")) {
                primaryExp.setYou(words.get(pos++));
            } else {
                ifRight = 0;
                primaryExp.setWrong();
            }
        } else if (words.get(pos).getLeiBie().equals("IDENFR")) {
            primaryExp.setLeibie(2);
            primaryExp.setlVal(parseLval());
        } else if (words.get(pos).getLeiBie().equals("INTCON")) {
            primaryExp.setLeibie(3);
            primaryExp.setNumber(parseNumber());
        } else {
            primaryExp.setLeibie(4);
            primaryExp.setCharacter(parseCharacte());
        }
        return primaryExp;
    }

    public Number parseNumber() {
        return new Number(words.get(pos++));
    }

    public Characte parseCharacte() {
        return new Characte(words.get(pos++));
    }

    public FuncRParams parseFuncRParams() {
        FuncRParams funcRParams = new FuncRParams();
        funcRParams.addExp(parseExp());
        while (words.get(pos).getStr().equals(",")) {
            funcRParams.addWord(words.get(pos++));
            funcRParams.addExp(parseExp());
        }
        return funcRParams;
    }

    public UnaryOp parseUnaryOp() {
        return new UnaryOp(words.get(pos++));
    }

    public LVal parseLval() {
        LVal lVal = new LVal();
        lVal.addWord(words.get(pos++));
        if (words.get(pos).getStr().equals("[")) {
            lVal.addWord(words.get(pos++));
            lVal.setExp(parseExp());
            if (words.get(pos).getStr().equals("]")) {
                lVal.addWord(words.get(pos++));
            } else {
                ifRight = 0;
                lVal.setWrong();
            }
        }
        return lVal;
    }

    public FuncFParams parseFuncFParams() {
        FuncFParams funcFParams = new FuncFParams();
        funcFParams.addFuncFParam(parseFuncFParam());
        while (words.get(pos).getStr().equals(",")) {
            funcFParams.addWord(words.get(pos++));
            funcFParams.addFuncFParam(parseFuncFParam());
        }
        return funcFParams;
    }

    public FuncFParam parseFuncFParam() {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.setbType(parseBType());
        funcFParam.addWord(words.get(pos++));
        if (words.get(pos).getStr().equals("[")) {
            funcFParam.addWord(words.get(pos++));
            if (!words.get(pos).getStr().equals("]")) {
                ifRight = 0;
                funcFParam.setWrong();
            } else {
                funcFParam.addWord(words.get(pos++));
            }
        }
        return funcFParam;
    }

    public FuncType parseFuncType() {
        return new FuncType(words.get(pos++));
    }

    public Decl parseDecl() {
        if (words.get(pos).getStr().equals("const")) {
            ConstDecl constDecl = new ConstDecl();
            constDecl.addWord(words.get(pos++));
            constDecl.setbType(parseBType());
            constDecl.addDef(parseConstDef());
            while (words.get(pos).getStr().equals(",")) {
                constDecl.addWord(words.get(pos++));
                constDecl.addDef(parseConstDef());
            }
            if (!words.get(pos).getStr().equals(";")) {
                ifRight = 0;
                constDecl.setWrong();
            } else {
                constDecl.addWord(words.get(pos++));
            }
            return constDecl;
        } else {
            VarDecl varDecl = new VarDecl();
            varDecl.setbType(parseBType());
            varDecl.addDef(parseVarDef());
            while (words.get(pos).getStr().equals(",")) {
                varDecl.addWord(words.get(pos++));
                varDecl.addDef(parseVarDef());
            }
            if (!words.get(pos).getStr().equals(";")) {
                ifRight = 0;
                varDecl.setWrong();
            } else {
                varDecl.addWord(words.get(pos++));
            }

            return varDecl;
        }
    }

    public BType parseBType() {
        return new BType(words.get(pos++));
    }

    public ConstDef parseConstDef() {
        ConstDef constDef = new ConstDef();
        constDef.addWord(words.get(pos++));
        if (words.get(pos).getStr().equals("[")) {
            constDef.addWord(words.get(pos++));
            constDef.setConstExp(parseConstExp());
            if (!words.get(pos).getStr().equals("]")) {
                ifRight = 0;
                constDef.setWrong();
            } else {
                constDef.addWord(words.get(pos++));
            }
        }
        constDef.addWord(words.get(pos++));
        constDef.setConstInitVal(parseConstInitVal());
        return constDef;
    }

    public VarDef parseVarDef() {
        VarDef varDef = new VarDef();
        varDef.addWord(words.get(pos++));
        if (words.get(pos).getStr().equals("[")) {
            varDef.addWord(words.get(pos++));
            varDef.setConstExp(parseConstExp());
            if (!words.get(pos).getStr().equals("]")) {
                ifRight = 0;
                varDef.setWrong();
            } else {
                varDef.addWord(words.get(pos++));
            }
        }
        if (words.get(pos).getStr().equals("=")) {
            varDef.addWord(words.get(pos++));
            varDef.setInitVal(parseInitVal());
        }
        return varDef;
    }

    public ConstExp parseConstExp() {
        return new ConstExp(parseAddExp());
    }

    public Exp parseExp() {
        return new Exp(parseAddExp());
    }

    public InitVal parseInitVal() {
        InitVal initVal = new InitVal();
        if (words.get(pos).getLeiBie().equals("STRCON")) {
            initVal.addWord(words.get(pos++));
        } else if (words.get(pos).getStr().equals("{")) {
            initVal.addWord(words.get(pos++));
            if (words.get(pos).getStr().equals("}")) {
                initVal.addWord(words.get(pos++));
            } else {
                initVal.addExp(parseExp());
                while (words.get(pos).getStr().equals(",")) {
                    initVal.addWord(words.get(pos++));
                    initVal.addExp(parseExp());
                }
                initVal.addWord(words.get(pos++));
            }
        } else {
            initVal.addExp(parseExp());
        }
        return initVal;

    }

    public ConstInitVal parseConstInitVal() {
        ConstInitVal constInitVal = new ConstInitVal();
        if (words.get(pos).getLeiBie().equals("STRCON")) {
            constInitVal.addWord(words.get(pos++));
        } else if (words.get(pos).getStr().equals("{")) {
            constInitVal.addWord(words.get(pos++));
            if (words.get(pos).getStr().equals("}")) {
                constInitVal.addWord(words.get(pos++));
            } else {
                constInitVal.addConstExp(parseConstExp());
                while (words.get(pos).getStr().equals(",")) {
                    constInitVal.addWord(words.get(pos++));
                    constInitVal.addConstExp(parseConstExp());
                }
                constInitVal.addWord(words.get(pos++));
            }
        } else {
            constInitVal.addConstExp(parseConstExp());
        }
        return constInitVal;
    }

}
