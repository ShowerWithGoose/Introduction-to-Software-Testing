package frontend;

import java.util.ArrayList;
import java.util.Objects;

public class Parser {
    private final Lexer lexer;
    private ArrayList<Integer> error_line;
    private ArrayList<java.lang.Character> error_type;
    private int p = 0;

    public Parser(Lexer lexer) {
        this.lexer = lexer;
        this.error_line = new ArrayList<>();
        this.error_type = new ArrayList<>();
    }

    public ArrayList<Integer> getError_line() {
        return error_line;
    }

    public ArrayList<java.lang.Character> getError_type() {
        return error_type;
    }

    public CompUnit parseCompUnit() {
        CompUnit compUnit = new CompUnit();
        while (isDecl()) {
            compUnit.addSon(parseDecl());
        }
        while (isFuncDef()) {
            compUnit.addSon(parseFuncDef());
        }
        compUnit.addSon(parseMainFuncDef());
        return compUnit;
    }

    public boolean isDecl() {
        if (Objects.equals(lexer.getCurToken(), "const")) {
            return true;
        }

        int foreLine = lexer.getForeLine();
        int line = lexer.getLine();
        int pos = lexer.getPos();
        char curChar = lexer.getCurChar();
        String curToken = lexer.getCurToken();
        String curType = lexer.getCurType();

        lexer.getSymbol();

        if (Objects.equals(lexer.getCurToken(), "main")) {
            lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
            return false;
        }

        lexer.getSymbol();

        if (Objects.equals(lexer.getCurToken(), "(")) {
            lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
            return false;
        }

        lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
        return true;
    }

    public boolean isFuncDef() {

        int foreLine = lexer.getForeLine();
        int line = lexer.getLine();
        int pos = lexer.getPos();
        char curChar = lexer.getCurChar();
        String curToken = lexer.getCurToken();
        String curType = lexer.getCurType();

        lexer.getSymbol();

        if (Objects.equals(lexer.getCurToken(), "main")) {
            lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
            return false;
        }

        lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
        return true;
    }

    public Decl parseDecl() {
        Decl decl = new Decl();
        if (Objects.equals(lexer.getCurToken(), "const")) {
            decl.addSon(parseConstDecl());
        } else {
            decl.addSon(parseVarDecl());
        }
        return decl;
    }

    public ConstDecl parseConstDecl() {
        ConstDecl constDecl = new ConstDecl();
        constDecl.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        constDecl.addSon(parseBType());
        constDecl.addSon(parseConstDef());
        while (Objects.equals(lexer.getCurToken(), ",")) {
            constDecl.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            constDecl.addSon(parseConstDef());
        }
        if (Objects.equals(lexer.getCurToken(), ";")) {
            constDecl.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
        } else {
            error_line.add(lexer.getForeLine());
            error_type.add('i');
        }
        return constDecl;
    }

    public BType parseBType() {
        BType bType = new BType();
        bType.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        return bType;
    }

    public ConstDef parseConstDef() {
        ConstDef constDef = new ConstDef();
        constDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        if (Objects.equals(lexer.getCurToken(), "[")) {
            constDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            constDef.addSon(parseConstExp());
            if (Objects.equals(lexer.getCurToken(), "]")) {
                constDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('k');
            }
        }
        constDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        constDef.addSon(parseConstInitVal());
        return constDef;
    }

    public ConstInitVal parseConstInitVal() {
        ConstInitVal constInitVal = new ConstInitVal();
        if (Objects.equals(lexer.getCurToken(), "{")) {
            constInitVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (!Objects.equals(lexer.getCurToken(), "}")) {
                constInitVal.addSon(parseConstExp());
                while (Objects.equals(lexer.getCurToken(), ",")) {
                    constInitVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                    lexer.getSymbol();
                    constInitVal.addSon(parseConstExp());
                }
            }
            constInitVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
        } else if (Objects.equals(lexer.getCurType(), "STRCON")) {
            constInitVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
        } else {
            constInitVal.addSon(parseConstExp());
        }
        return constInitVal;
    }

    public VarDecl parseVarDecl() {
        VarDecl varDecl = new VarDecl();
        varDecl.addSon(parseBType());
        varDecl.addSon(parseVarDef());
        while (Objects.equals(lexer.getCurToken(), ",")) {
            varDecl.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            varDecl.addSon(parseVarDef());
        }
        if (Objects.equals(lexer.getCurToken(), ";")) {
            varDecl.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
        } else {
            error_line.add(lexer.getForeLine());
            error_type.add('i');
        }
        return varDecl;
    }

    public VarDef parseVarDef() {
        VarDef varDef = new VarDef();
        varDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        if (Objects.equals(lexer.getCurToken(), "[")) {
            varDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            varDef.addSon(parseConstExp());
            if (Objects.equals(lexer.getCurToken(), "]")) {
                varDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('k');
            }
        }
        if (Objects.equals(lexer.getCurToken(), "=")) {
            varDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            varDef.addSon(parseInitVal());
        }
        return varDef;
    }

    public InitVal parseInitVal() {
        InitVal initVal = new InitVal();
        if (Objects.equals(lexer.getCurToken(), "{")) {
            initVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (!Objects.equals(lexer.getCurToken(), "}")) {
                initVal.addSon(parseExp());
                while (Objects.equals(lexer.getCurToken(), ",")) {
                    initVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                    lexer.getSymbol();
                    initVal.addSon(parseExp());
                }
            }
            initVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
        } else if (Objects.equals(lexer.getCurType(), "STRCON")) {
            initVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
        } else {
            initVal.addSon(parseExp());
        }
        return initVal;
    }

    public FuncDef parseFuncDef() {
        FuncDef funcDef = new FuncDef();
        funcDef.addSon(parseFuncType());
        funcDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        funcDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        if (Objects.equals(lexer.getCurToken(), "int") || Objects.equals(lexer.getCurToken(), "char")) {
            funcDef.addSon(parseFuncFParams());
        }
        if (Objects.equals(lexer.getCurToken(), ")")) {
            funcDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
        } else {
            error_line.add(lexer.getForeLine());
            error_type.add('j');
        }
        funcDef.addSon(parseBlock());
        return funcDef;
    }

    public MainFuncDef parseMainFuncDef() {
        MainFuncDef mainFuncDef = new MainFuncDef();
        mainFuncDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        mainFuncDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        mainFuncDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        if (Objects.equals(lexer.getCurToken(), ")")) {
            mainFuncDef.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
        } else {
            error_line.add(lexer.getForeLine());
            error_type.add('j');
        }
        mainFuncDef.addSon(parseBlock());
        return mainFuncDef;
    }

    public FuncType parseFuncType() {
        FuncType funcType = new FuncType();
        funcType.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        return funcType;
    }

    public FuncFParams parseFuncFParams() {
        FuncFParams funcFParams = new FuncFParams();
        funcFParams.addSon(parseFuncFParam());
        while (Objects.equals(lexer.getCurToken(), ",")) {
            funcFParams.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            funcFParams.addSon(parseFuncFParam());
        }
        return funcFParams;
    }

    public FuncFParam parseFuncFParam() {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.addSon(parseBType());
        funcFParam.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        if (Objects.equals(lexer.getCurToken(), "[")) {
            funcFParam.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (Objects.equals(lexer.getCurToken(), "]")) {
                funcFParam.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('k');
            }
        }
        return funcFParam;
    }

    public Block parseBlock() {
        Block block = new Block();
        block.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        while (!Objects.equals(lexer.getCurToken(), "}")) {
            block.addSon(parseBlockItem());
        }
        block.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        return block;
    }

    public BlockItem parseBlockItem() {
        BlockItem blockItem = new BlockItem();
        if (Objects.equals(lexer.getCurToken(), "const") || Objects.equals(lexer.getCurToken(), "int") || Objects.equals(lexer.getCurToken(), "char")) {
            blockItem.addSon(parseDecl());
        } else {
            blockItem.addSon(parseStmt());
        }
        return blockItem;
    }

    public Stmt parseStmt() {
        Stmt stmt = new Stmt();
        if (Objects.equals(lexer.getCurToken(), "{")) {
            stmt.addSon(parseBlock());
        } else if (Objects.equals(lexer.getCurToken(), "if")) {
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            stmt.addSon(parseCond());
            if (Objects.equals(lexer.getCurToken(), ")")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('j');
            }
            stmt.addSon(parseStmt());
            if (Objects.equals(lexer.getCurToken(), "else")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
                stmt.addSon(parseStmt());
            }
        } else if (Objects.equals(lexer.getCurToken(), "for")) {
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (!Objects.equals(lexer.getCurToken(), ";")) {
                stmt.addSon(parseForStmt());
            }
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (!Objects.equals(lexer.getCurToken(), ";")) {
                stmt.addSon(parseCond());
            }
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (!Objects.equals(lexer.getCurToken(), ")")) {
                stmt.addSon(parseForStmt());
            }
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            stmt.addSon(parseStmt());
        } else if (Objects.equals(lexer.getCurToken(), "break") || Objects.equals(lexer.getCurToken(), "continue")) {
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (Objects.equals(lexer.getCurToken(), ";")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('i');
            }
        } else if (Objects.equals(lexer.getCurToken(), "return")) {
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (Objects.equals(lexer.getCurToken(), "(") || Objects.equals(lexer.getCurType(), "IDENFR")
                    || Objects.equals(lexer.getCurType(), "INTCON") || Objects.equals(lexer.getCurType(), "CHRCON")
                    || Objects.equals(lexer.getCurToken(), "+") || Objects.equals(lexer.getCurToken(), "-") || Objects.equals(lexer.getCurToken(), "!")) {
                stmt.addSon(parseExp());
            }
            if (Objects.equals(lexer.getCurToken(), ";")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('i');
            }
        } else if (Objects.equals(lexer.getCurToken(), "printf")) {
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            while (Objects.equals(lexer.getCurToken(), ",")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
                stmt.addSon(parseExp());
            }
            if (Objects.equals(lexer.getCurToken(), ")")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('j');
            }
            if (Objects.equals(lexer.getCurToken(), ";")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('i');
            }
        } else if (isLvalAssign()) {
            stmt.addSon(parseLVal());
            stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (Objects.equals(lexer.getCurToken(), "getint") || Objects.equals(lexer.getCurToken(), "getchar")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
                if (Objects.equals(lexer.getCurToken(), ")")) {
                    stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                    lexer.getSymbol();
                } else {
                    error_line.add(lexer.getForeLine());
                    error_type.add('j');
                }
            } else {
                stmt.addSon(parseExp());
            }
            if (Objects.equals(lexer.getCurToken(), ";")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('i');
            }
        } else {
            if (Objects.equals(lexer.getCurToken(), "(") || Objects.equals(lexer.getCurType(), "IDENFR")
                    || Objects.equals(lexer.getCurType(), "INTCON") || Objects.equals(lexer.getCurType(), "CHRCON")
                    || Objects.equals(lexer.getCurToken(), "+") || Objects.equals(lexer.getCurToken(), "-") || Objects.equals(lexer.getCurToken(), "!")) {
                stmt.addSon(parseExp());
            }
            if (Objects.equals(lexer.getCurToken(), ";")) {
                stmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('i');
            }
        }
        return stmt;
    }


    public boolean isLvalAssign() {

        if (!Objects.equals(lexer.getCurType(), "IDENFR")) {
            return false;
        }

        int foreLine = lexer.getForeLine();
        int line = lexer.getLine();
        int pos = lexer.getPos();
        char curChar = lexer.getCurChar();
        String curToken = lexer.getCurToken();
        String curType = lexer.getCurType();

        lexer.getSymbol();
        if (Objects.equals(lexer.getCurToken(), "(")) {
            lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
            return false;
        }

        lexer.setBack(foreLine, line, pos, curChar, curToken, curType);

        p = 1;
        parseLVal();
        p = 0;
        if (Objects.equals(lexer.getCurToken(), "=")) {
            lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
            return true;
        }

        lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
        return false;
    }

    public ForStmt parseForStmt() {
        ForStmt forStmt = new ForStmt();
        forStmt.addSon(parseLVal());
        forStmt.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        forStmt.addSon(parseExp());
        return forStmt;
    }

    public Exp parseExp() {
        Exp exp = new Exp();
        exp.addSon(parseAddExp());
        return exp;
    }

    public Cond parseCond() {
        Cond cond = new Cond();
        cond.addSon(parseLOrExp());
        return cond;
    }

    public LVal parseLVal() {
        LVal lVal = new LVal();
        lVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        if (Objects.equals(lexer.getCurToken(), "[")) {
            lVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            lVal.addSon(parseExp());
            if (Objects.equals(lexer.getCurToken(), "]")) {
                lVal.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                if (p == 0) {
                    error_line.add(lexer.getForeLine());
                    error_type.add('k');
                }
            }
        }
        return lVal;
    }

    public PrimaryExp parsePrimaryExp() {
        PrimaryExp primaryExp = new PrimaryExp();
        if (Objects.equals(lexer.getCurToken(), "(")) {
            primaryExp.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            primaryExp.addSon(parseExp());
            if (Objects.equals(lexer.getCurToken(), ")")) {
                primaryExp.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('j');
            }
        } else if (Objects.equals(lexer.getCurType(), "IDENFR")) {
            primaryExp.addSon(parseLVal());
        } else if (Objects.equals(lexer.getCurType(), "INTCON")) {
            primaryExp.addSon(parseNumber());
        } else if (Objects.equals(lexer.getCurType(), "CHRCON")) {
            primaryExp.addSon(parseCharacter());
        }
        return primaryExp;
    }

    public Number parseNumber() {
        Number number = new Number();
        number.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        return number;
    }

    public Character parseCharacter() {
        Character character = new Character();
        character.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        return character;
    }

    public UnaryExp parseUnaryExp() {
        UnaryExp unaryExp = new UnaryExp();
        if (Objects.equals(lexer.getCurToken(), "+") || Objects.equals(lexer.getCurToken(), "-") || Objects.equals(lexer.getCurToken(), "!")) {
            unaryExp.addSon(parseUnaryOp());
            unaryExp.addSon(parseUnaryExp());
        } else if (isHanShu()) {
            unaryExp.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            unaryExp.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            if (Objects.equals(lexer.getCurToken(), "(") || Objects.equals(lexer.getCurType(), "IDENFR")
                    || Objects.equals(lexer.getCurType(), "INTCON") || Objects.equals(lexer.getCurType(), "CHRCON")
                    || Objects.equals(lexer.getCurToken(), "+") || Objects.equals(lexer.getCurToken(), "-") || Objects.equals(lexer.getCurToken(), "!")) {
                unaryExp.addSon(parseFuncRParams());
            }
            if (Objects.equals(lexer.getCurToken(), ")")) {
                unaryExp.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
                lexer.getSymbol();
            } else {
                error_line.add(lexer.getForeLine());
                error_type.add('j');
            }
        } else {
            unaryExp.addSon(parsePrimaryExp());
        }
        return unaryExp;
    }

    public boolean isHanShu() {

        int foreLine = lexer.getForeLine();
        int line = lexer.getLine();
        int pos = lexer.getPos();
        char curChar = lexer.getCurChar();
        String curToken = lexer.getCurToken();
        String curType = lexer.getCurType();

        if (!Objects.equals(lexer.getCurType(), "IDENFR")) {
            return false;
        }
        lexer.getSymbol();
        if (Objects.equals(lexer.getCurToken(), "(")) {
            lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
            return true;
        }
        lexer.setBack(foreLine, line, pos, curChar, curToken, curType);
        return false;
    }

    public UnaryOp parseUnaryOp() {
        UnaryOp unaryOp = new UnaryOp();
        unaryOp.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
        lexer.getSymbol();
        return unaryOp;
    }

    public FuncRParams parseFuncRParams() {
        FuncRParams funcRParams = new FuncRParams();
        funcRParams.addSon(parseExp());
        while (Objects.equals(lexer.getCurToken(), ",")) {
            funcRParams.addSon(new Terminal(lexer.getCurToken(), lexer.getCurType(), lexer.getLine()));
            lexer.getSymbol();
            funcRParams.addSon(parseExp());
        }
        return funcRParams;
    }

    public MulExp parseMulExp() {
        MulExp mulExp = new MulExp();
        ArrayList<Token> unaryExps = new ArrayList<>();
        ArrayList<String> tokens = new ArrayList<>();
        ArrayList<String> types = new ArrayList<>();
        ArrayList<Integer> lines = new ArrayList<>();
        ArrayList<Token> mulExps = new ArrayList<>();

        unaryExps.add(parseUnaryExp());

        while (Objects.equals(lexer.getCurToken(), "*") || Objects.equals(lexer.getCurToken(), "/") || Objects.equals(lexer.getCurToken(), "%")) {
            tokens.add(lexer.getCurToken());
            types.add(lexer.getCurType());
            lines.add(lexer.getLine());
            lexer.getSymbol();
            unaryExps.add(parseUnaryExp());
        }

        for (int i = 0; i < unaryExps.size() - 1; i++) {
            MulExp mulExp1 = new MulExp();
            if (i != 0) {
                mulExp1.addSon(mulExps.get(i - 1));
                mulExp1.addSon(new Terminal(tokens.get(i - 1), types.get(i - 1), lines.get(i - 1)));
            }
            mulExp1.addSon(unaryExps.get(i));
            mulExps.add(mulExp1);
        }
        if (unaryExps.size() == 1) {
            mulExp.addSon(unaryExps.get(0));
        } else {
            mulExp.addSon(mulExps.get(unaryExps.size() - 2));
            mulExp.addSon(new Terminal(tokens.get(unaryExps.size() - 2), types.get(unaryExps.size() - 2), lines.get(unaryExps.size() - 2)));
            mulExp.addSon(unaryExps.get(unaryExps.size() - 1));
        }

        return mulExp;
    }

    public AddExp parseAddExp() {

        AddExp addExp = new AddExp();

        ArrayList<Token> mulExps = new ArrayList<>();
        ArrayList<String> tokens = new ArrayList<>();
        ArrayList<String> types = new ArrayList<>();
        ArrayList<Integer> lines = new ArrayList<>();
        ArrayList<Token> addExps = new ArrayList<>();

        mulExps.add(parseMulExp());

        while (Objects.equals(lexer.getCurToken(), "+") || Objects.equals(lexer.getCurToken(), "-")) {
            tokens.add(lexer.getCurToken());
            types.add(lexer.getCurType());
            lines.add(lexer.getLine());
            lexer.getSymbol();
            mulExps.add(parseMulExp());
        }

        for (int i = 0; i < mulExps.size() - 1; i++) {
            AddExp addExp1 = new AddExp();
            if (i != 0) {
                addExp1.addSon(addExps.get(i - 1));
                addExp1.addSon(new Terminal(tokens.get(i - 1), types.get(i - 1), lines.get(i - 1)));
            }
            addExp1.addSon(mulExps.get(i));
            addExps.add(addExp1);
        }
        if (mulExps.size() == 1) {
            addExp.addSon(mulExps.get(0));
        } else {
            int l = mulExps.size();
            addExp.addSon(addExps.get(l - 2));
            addExp.addSon(new Terminal(tokens.get(l - 2), types.get(l - 2), lines.get(l - 2)));
            addExp.addSon(mulExps.get(l - 1));
        }

        return addExp;
    }

    public RelExp parseRelExp() {
        RelExp relExp = new RelExp();

        ArrayList<Token> addExps = new ArrayList<>();
        ArrayList<String> tokens = new ArrayList<>();
        ArrayList<String> types = new ArrayList<>();
        ArrayList<Integer> lines = new ArrayList<>();
        ArrayList<Token> relExps = new ArrayList<>();

        addExps.add(parseAddExp());

        while (Objects.equals(lexer.getCurToken(), ">") || Objects.equals(lexer.getCurToken(), "<")
                || Objects.equals(lexer.getCurToken(), ">=") || Objects.equals(lexer.getCurToken(), "<=")) {
            tokens.add(lexer.getCurToken());
            types.add(lexer.getCurType());
            lines.add(lexer.getLine());
            lexer.getSymbol();
            addExps.add(parseAddExp());
        }

        for (int i = 0; i < addExps.size() - 1; i++) {
            RelExp relExp1 = new RelExp();
            if (i != 0) {
                relExp1.addSon(relExps.get(i - 1));
                relExp1.addSon(new Terminal(tokens.get(i - 1), types.get(i - 1), lines.get(i - 1)));
            }
            relExp1.addSon(addExps.get(i));
            relExps.add(relExp1);
        }
        if (addExps.size() == 1) {
            relExp.addSon(addExps.get(0));
        } else {
            int l = addExps.size();
            relExp.addSon(relExps.get(l - 2));
            relExp.addSon(new Terminal(tokens.get(l - 2), types.get(l - 2), lines.get(l - 2)));
            relExp.addSon(addExps.get(l - 1));
        }

        return relExp;
    }

    public EqExp parseEqExp() {
        EqExp eqExp = new EqExp();

        ArrayList<Token> relExps = new ArrayList<>();
        ArrayList<String> tokens = new ArrayList<>();
        ArrayList<String> types = new ArrayList<>();
        ArrayList<Integer> lines = new ArrayList<>();
        ArrayList<Token> eqExps = new ArrayList<>();

        relExps.add(parseRelExp());

        while (Objects.equals(lexer.getCurToken(), "==") || Objects.equals(lexer.getCurToken(), "!=")) {
            tokens.add(lexer.getCurToken());
            types.add(lexer.getCurType());
            lines.add(lexer.getLine());
            lexer.getSymbol();
            relExps.add(parseRelExp());
        }

        for (int i = 0; i < relExps.size() - 1; i++) {
            EqExp eqExp1 = new EqExp();
            if (i != 0) {
                eqExp1.addSon(eqExps.get(i - 1));
                eqExp1.addSon(new Terminal(tokens.get(i - 1), types.get(i - 1), lines.get(i - 1)));
            }
            eqExp1.addSon(relExps.get(i));
            eqExps.add(eqExp1);
        }
        if (relExps.size() == 1) {
            eqExp.addSon(relExps.get(0));
        } else {
            int l = relExps.size();
            eqExp.addSon(eqExps.get(l - 2));
            eqExp.addSon(new Terminal(tokens.get(l - 2), types.get(l - 2), lines.get(l - 2)));
            eqExp.addSon(relExps.get(l - 1));
        }

        return eqExp;
    }

    public LAndExp parseLAndExp() {
        LAndExp lAndExp = new LAndExp();

        ArrayList<Token> eqExps = new ArrayList<>();
        ArrayList<String> tokens = new ArrayList<>();
        ArrayList<String> types = new ArrayList<>();
        ArrayList<Integer> lines = new ArrayList<>();
        ArrayList<Token> lAndExps = new ArrayList<>();

        eqExps.add(parseEqExp());

        while (Objects.equals(lexer.getCurToken(), "&&") || Objects.equals(lexer.getCurToken(), "&")) {
            if (Objects.equals(lexer.getCurToken(), "&")) {
                error_line.add(lexer.getLine());
                error_type.add('a');
            }
            tokens.add(lexer.getCurToken());
            types.add(lexer.getCurType());
            lines.add(lexer.getLine());
            lexer.getSymbol();
            eqExps.add(parseEqExp());
        }

        for (int i = 0; i < eqExps.size() - 1; i++) {
            LAndExp lAndExp1 = new LAndExp();
            if (i != 0) {
                lAndExp1.addSon(lAndExps.get(i - 1));
                lAndExp1.addSon(new Terminal(tokens.get(i - 1), types.get(i - 1), lines.get(i - 1)));
            }
            lAndExp1.addSon(eqExps.get(i));
            lAndExps.add(lAndExp1);
        }
        if (eqExps.size() == 1) {
            lAndExp.addSon(eqExps.get(0));
        } else {
            int l = eqExps.size();
            lAndExp.addSon(lAndExps.get(l - 2));
            lAndExp.addSon(new Terminal(tokens.get(l - 2), types.get(l - 2), lines.get(l - 2)));
            lAndExp.addSon(eqExps.get(l - 1));
        }

        return lAndExp;
    }

    public LOrExp parseLOrExp() {
        LOrExp lOrExp = new LOrExp();

        ArrayList<Token> lAndExps = new ArrayList<>();
        ArrayList<String> tokens = new ArrayList<>();
        ArrayList<String> types = new ArrayList<>();
        ArrayList<Integer> lines = new ArrayList<>();
        ArrayList<Token> lOrExps = new ArrayList<>();

        lAndExps.add(parseLAndExp());

        while (Objects.equals(lexer.getCurToken(), "||") || Objects.equals(lexer.getCurToken(), "|")) {
            if (Objects.equals(lexer.getCurToken(), "|")) {
                error_line.add(lexer.getLine());
                error_type.add('a');
            }
            tokens.add(lexer.getCurToken());
            types.add(lexer.getCurType());
            lines.add(lexer.getLine());
            lexer.getSymbol();
            lAndExps.add(parseLAndExp());
        }

        for (int i = 0; i < lAndExps.size() - 1; i++) {
            LOrExp lOrExp1 = new LOrExp();
            if (i != 0) {
                lOrExp1.addSon(lOrExps.get(i - 1));
                lOrExp1.addSon(new Terminal(tokens.get(i - 1), types.get(i - 1), lines.get(i - 1)));
            }
            lOrExp1.addSon(lAndExps.get(i));
            lOrExps.add(lOrExp1);
        }
        if (lAndExps.size() == 1) {
            lOrExp.addSon(lAndExps.get(0));
        } else {
            int l = lAndExps.size();
            lOrExp.addSon(lOrExps.get(l - 2));
            lOrExp.addSon(new Terminal(tokens.get(l - 2), types.get(l - 2), lines.get(l - 2)));
            lOrExp.addSon(lAndExps.get(l - 1));
        }

        return lOrExp;
    }

    public ConstExp parseConstExp() {
        ConstExp constExp = new ConstExp();
        constExp.addSon(parseAddExp());
        return constExp;
    }

}