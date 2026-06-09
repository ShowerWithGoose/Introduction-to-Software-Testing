package frontend;
import frontend.SyntaxTree.*;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Parser {
    private ArrayList<Token> tokens;
    private Token curToken;
    private int curPos;
    private FileWriter parserWriter;
    private ArrayList<ErrorInfo> errors;
    private boolean isOutput;

    public Parser(ArrayList<Token> tokens, FileWriter parserWriter, ArrayList<ErrorInfo> errors) {
        this.tokens = tokens;
        this.curPos = 0;
        this.curToken = tokens.get(0);
        this.parserWriter = parserWriter;
        this.errors = errors;
    }

    public ArrayList<ErrorInfo> getErrors() {
        return errors;
    }

    public Token getNextToken() throws IOException {
        if (isOutput) {
//        System.out.println(curToken.toString());
            parserWriter.write(curToken.toString() + "\n");
        }
        this.curPos++;
        if (this.curPos < this.tokens.size()) {
            this.curToken = this.tokens.get(this.curPos);
            return this.curToken;
        }
        return null;
    }

    public Token getNextToken(int step) {
        if (this.curPos + step < this.tokens.size()) {
            return this.tokens.get(this.curPos + step);
        }
        return null;
    }

    // CompUnit → {Decl} {FuncDef} MainFuncDef
    public CompUnit parseCompUnit() throws IOException {
        CompUnit compUnit = new CompUnit();
        while (getNextToken(1).getType() != TokenType.MAINTK) {
            if (getNextToken(2).getType() == TokenType.LPARENT) {
                compUnit.addFuncDef(parseFuncDef());
            } else {
                compUnit.addDecl(parseDecl());
            }
        }
        compUnit.setMainFuncDef(parseMainFuncDef());
        if (isOutput) {
//        System.out.println("<CompUnit>");
            parserWriter.write("<CompUnit>\n");
        }
        return compUnit;
    }

    // Decl → ConstDecl | VarDecl
    public Decl parseDecl() throws IOException {
        Decl decl;
        if (this.curToken.getType() == TokenType.INTTK || this.curToken.getType() == TokenType.CHARTK) {
            decl = new Decl(parseVarDecl());
            return decl;
        } else if (this.curToken.getType() == TokenType.CONSTTK) {
            decl = new Decl(parseConstDecl());
            return decl;
        }
        System.out.println("Error: Invalid declaration at line " + this.curToken.getLine());
        return null;
    }

    // VarDecl → BType VarDef { ',' VarDef } ';' //i
    public VarDecl parseVarDecl() throws IOException {
        VarDecl varDecl = new VarDecl();
        varDecl.setBType(parseBType());
        VarDef varDef = parseVarDef(); //需要读到下一个token
        varDecl.addVarDef(varDef);

        while (this.curToken.getType() == TokenType.COMMA) {
            getNextToken();
            varDef = parseVarDef();
            varDecl.addVarDef(varDef);
        }

        if (this.curToken.getType() == TokenType.SEMICN) {
            getNextToken();
        } else {
            errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
            System.out.println("Error: i" + getNextToken(-1).getLine());
        }
        if (isOutput) {
//        System.out.println("<VarDecl>");
            parserWriter.write("<VarDecl>\n");
        }
        return varDecl;
    }

    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // b k
    public VarDef parseVarDef() throws IOException {
        VarDef varDef = new VarDef();
        if (this.curToken.getType() == TokenType.IDENFR) {
            varDef.setIdent(this.curToken);
            getNextToken();
            if(this.curToken.getType() == TokenType.LBRACK) {
                getNextToken();
                ConstExp constExp = parseConstExp(); //需要读到下一个token
                varDef.setConstExp(constExp);
                if(this.curToken.getType() == TokenType.RBRACK) {
                    getNextToken();
                } else {
                    errors.add(new ErrorInfo('k', getNextToken(-1).getLine()));
                    System.out.println("Error: k" + getNextToken(-1).getLine());
                }
            }
            if(this.curToken.getType() == TokenType.ASSIGN) {
                getNextToken();
                InitVal initVal = parseInitVal(); //需要读到下一个token
                varDef.setInitVal(initVal);
            }
        }
        if (isOutput) {
//        System.out.println("<VarDef>");
            parserWriter.write("<VarDef>\n");
        }
        return varDef;
    }

    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public InitVal parseInitVal() throws IOException {
        InitVal initVal = new InitVal();
        if (this.curToken.getType() == TokenType.LBRACE) {
            getNextToken();
            if (this.curToken.getType() != TokenType.RBRACE) {
                Exp exp = parseExp();
                initVal.addExp(exp);
                while (this.curToken.getType() == TokenType.COMMA) {
                    getNextToken();
                    exp = parseExp();
                    initVal.addExp(exp);
                }
                if (this.curToken.getType() == TokenType.RBRACE) {
                    getNextToken();
                }
            } else {
                getNextToken();
            }
        } else if (this.curToken.getType() == TokenType.STRCON) {
            initVal.setStringConst(this.curToken.getValue());
            getNextToken();
        } else {
            Exp exp = parseExp();
            initVal.addExp(exp);
        }
        if (isOutput) {
//        System.out.println("<InitVal>");
            parserWriter.write("<InitVal>\n");
        }
        return initVal;
    }

    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    public ConstDecl parseConstDecl() throws IOException {
        ConstDecl constDecl = new ConstDecl();
        getNextToken();
        if (this.curToken.getType() == TokenType.INTTK || this.curToken.getType() == TokenType.CHARTK) {
            constDecl.setBType(parseBType());

            ConstDef constDef = parseConstDef(); //需要读到下一个token
            constDecl.addConstDef(constDef);

            while (this.curToken.getType() == TokenType.COMMA) {
                getNextToken();
                constDef = parseConstDef();
                constDecl.addConstDef(constDef);
            }
        }
        if (this.curToken.getType() == TokenType.SEMICN) {
            getNextToken();
        } else {
            errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
            System.out.println("Error: i" + getNextToken(-1).getLine());
        }
        if (isOutput) {
//        System.out.println("<ConstDecl>");
            parserWriter.write("<ConstDecl>\n");
        }
        return constDecl;
    }

    // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    public ConstDef parseConstDef() throws IOException {
        ConstDef constDef = new ConstDef();
        if (this.curToken.getType() == TokenType.IDENFR) {
            constDef.setIdent(this.curToken);
            getNextToken();
            if(this.curToken.getType() == TokenType.LBRACK) {
                getNextToken();
                ConstExp constExp = parseConstExp(); //需要读到下一个token
                constDef.setConstExp(constExp);
                if(this.curToken.getType() == TokenType.RBRACK) {
                    getNextToken();
                } else {
                    errors.add(new ErrorInfo('k', getNextToken(-1).getLine()));
                    System.out.println("Error: k" + getNextToken(-1).getLine());
                }
            }
            if(this.curToken.getType() == TokenType.ASSIGN) {
                getNextToken();
                ConstInitVal constInitVal = parseConstInitVal();
                constDef.setConstInitVal(constInitVal);
            }
        }
        if (isOutput) {
//        System.out.println("<ConstDef>");
            parserWriter.write("<ConstDef>\n");
        }
        return constDef;
    }

    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public ConstInitVal parseConstInitVal() throws IOException {
        ConstInitVal constInitVal = new ConstInitVal();
        if(this.curToken.getType() == TokenType.LBRACE) {
            getNextToken();
            if (this.curToken.getType() != TokenType.RBRACE) {
                ConstExp constExp = parseConstExp(); //需要读到下一个token
                constInitVal.addConstExp(constExp);
                while (this.curToken.getType() == TokenType.COMMA) {
                    getNextToken();
                    constExp = parseConstExp();
                    constInitVal.addConstExp(constExp);
                }
                if (this.curToken.getType() == TokenType.RBRACE) {
                    getNextToken();
                }
            } else {
                getNextToken();
            }
        } else if(this.curToken.getType() == TokenType.STRCON) {
            constInitVal.setStringConst(this.curToken.getValue());
            getNextToken();
        } else {
            ConstExp constExp = parseConstExp();
            constInitVal.addConstExp(constExp);
        }
        if (isOutput) {
//        System.out.println("<ConstInitVal>");
            parserWriter.write("<ConstInitVal>\n");
        }
        return constInitVal;
    }

    public BType parseBType() throws IOException {
        BType bType = new BType(this.curToken.getType());
        getNextToken();
        return bType;
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // b g j
    public FuncDef parseFuncDef() throws IOException {
        FuncDef funcDef = new FuncDef();
        funcDef.setFuncType(parseFuncType());
        if (this.curToken.getType() == TokenType.IDENFR) {
            funcDef.setIdent(this.curToken);
            getNextToken();
            if (this.curToken.getType() == TokenType.LPARENT) {
                getNextToken();
                if (this.curToken.getType() != TokenType.RPARENT && this.curToken.getType() != TokenType.LBRACE) {
                    FuncFParams funcFParams = parseFuncFParams();
                    funcDef.setFuncFParams(funcFParams);
                }
                if (this.curToken.getType() == TokenType.RPARENT) {
                    getNextToken();
                } else {
                    errors.add(new ErrorInfo('j', getNextToken(-1).getLine()));
                    System.out.println("Error: j" + getNextToken(-1).getLine());
                }
            }
            Block block = parseBlock();
            funcDef.setBlock(block);
        }
        if (isOutput) {
//        System.out.println("<FuncDef>");
            parserWriter.write("<FuncDef>\n");
        }
        return funcDef;
    }

    // FuncType → 'void' | 'int' | 'char'
    public FuncType parseFuncType() throws IOException {
        FuncType funcType = new FuncType(this.curToken.getType());
        getNextToken();
        if (isOutput) {
//        System.out.println("<FuncType>");
            parserWriter.write("<FuncType>\n");
        }
        return funcType;
    }

    // MainFuncDef → 'int' 'main' '(' ')' Block // j
    public MainFuncDef parseMainFuncDef() throws IOException {
        if (this.curToken.getType() == TokenType.INTTK) {
            getNextToken();
            if (this.curToken.getType() == TokenType.MAINTK) {
                getNextToken();
                if (this.curToken.getType() == TokenType.LPARENT) {
                    getNextToken();
                    if (this.curToken.getType() == TokenType.RPARENT) {
                        getNextToken();
                    } else {
                        errors.add(new ErrorInfo('j', getNextToken(-1).getLine()));
                        System.out.println("Error: j" + getNextToken(-1).getLine());
                    }
                    Block block = parseBlock();
                    if (isOutput) {
//                    System.out.println("<MainFuncDef>");
                        parserWriter.write("<MainFuncDef>\n");
                    }
                    return new MainFuncDef(block);
                }
            }
        }
        return null;
    }

    // FuncFParams → FuncFParam { ',' FuncFParam }
    public FuncFParams parseFuncFParams() throws IOException {
        FuncFParams funcFParams = new FuncFParams();
        FuncFParam funcFParam = parseFuncFParam();
        funcFParams.addFuncFParam(funcFParam);
        while (this.curToken.getType() == TokenType.COMMA) {
            getNextToken();
            funcFParam = parseFuncFParam();
            funcFParams.addFuncFParam(funcFParam);
        }
        if (isOutput) {
//        System.out.println("<FuncFParams>");
            parserWriter.write("<FuncFParams>\n");
        }
        return funcFParams;
    }

    // FuncFParam → BType Ident ['[' ']'] // k
    public FuncFParam parseFuncFParam() throws IOException {
        FuncFParam funcFParam = new FuncFParam();
        funcFParam.setBType(parseBType());
        if (this.curToken.getType() == TokenType.IDENFR) {
            funcFParam.setIdent(this.curToken);
            getNextToken();
            if (this.curToken.getType() == TokenType.LBRACK) {
                getNextToken();
                if (this.curToken.getType() == TokenType.RBRACK) {
                    getNextToken();
                } else {
                    errors.add(new ErrorInfo('k', getNextToken(-1).getLine()));
                    System.out.println("Error: k" + getNextToken(-1).getLine());
                }
            }
        }
        if (isOutput) {
//        System.out.println("<FuncFParam>");
            parserWriter.write("<FuncFParam>\n");
        }
        return funcFParam;
    }

    // Block → '{' { BlockItem } '}'
    public Block parseBlock() throws IOException {
        Block block = new Block();
        if (this.curToken.getType() == TokenType.LBRACE) {
            getNextToken();
            while (this.curToken.getType() != TokenType.RBRACE) {
                BlockItem blockItem = parseBlockItem();
                block.addBlockItem(blockItem);
            }
            if (this.curToken.getType() == TokenType.RBRACE) {
                getNextToken();
            }
        }
        if (isOutput) {
//        System.out.println("<Block>");
            parserWriter.write("<Block>\n");
        }
        return block;
    }

    // BlockItem → Decl | Stmt
    public BlockItem parseBlockItem() throws IOException {
        if (this.curToken.getType() == TokenType.INTTK || this.curToken.getType() == TokenType.CHARTK || this.curToken.getType() == TokenType.CONSTTK) {
            return new BlockItem(parseDecl());
        } else {
            return new BlockItem(parseStmt());
        }
    }

    public boolean tryParseLVal() throws IOException {
        this.isOutput = false;
        int pos = this.curPos;
        if (this.curToken.getType() == TokenType.IDENFR) {
            getNextToken();
            if (this.curToken.getType() == TokenType.LBRACK) {
                getNextToken();
                parseExp();
            }
            if(this.curToken.getType() == TokenType.RBRACK) {
                getNextToken();
            }
            if(this.curToken.getType() == TokenType.ASSIGN) {
                this.curPos = pos;
                this.curToken = this.tokens.get(this.curPos);
                this.isOutput = true;
                return true;
            }
        }
        this.curPos = pos;
        this.curToken = this.tokens.get(this.curPos);
        this.isOutput = true;
        return false;
    }

    // 语句 Stmt → LVal '=' Exp ';' // i
    // | [Exp] ';' // i
    // | Block
    // | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    // | 'break' ';' | 'continue' ';' // i
    // | 'return' [Exp] ';' // i
    // | LVal '=' 'getint''('')'';' // i j
    // | LVal '=' 'getchar''('')'';' // i j
    // | 'printf''('StringConst {','Exp}')'';' // i j
    public Stmt parseStmt() throws IOException {
        Stmt stmt = new Stmt();
        if (this.curToken.getType() == TokenType.IFTK) {
            getNextToken();
            if (this.curToken.getType() == TokenType.LPARENT) {
                getNextToken();
                stmt.setIfCond(parseCond());
                if (this.curToken.getType() == TokenType.RPARENT) {
                    getNextToken();
                } else {
                    errors.add(new ErrorInfo('j', getNextToken(-1).getLine()));
                    System.out.println("Error: j" + getNextToken(-1).getLine());
                }
                stmt.setIfStmt(parseStmt());
                if (this.curToken.getType() == TokenType.ELSETK) {
                    getNextToken();
                    stmt.setElseStmt(parseStmt());
                }
            }
        } else if (this.curToken.getType() == TokenType.FORTK) {
            getNextToken();
            if (this.curToken.getType() == TokenType.LPARENT) {
                getNextToken();
                if (this.curToken.getType() == TokenType.SEMICN) {
                    getNextToken();
                } else {
                    stmt.setForStmt1(parseForStmt());
                    getNextToken();
                }
                if (this.curToken.getType() == TokenType.SEMICN) {
                    getNextToken();
                } else {
                    stmt.setForCond(parseCond());
                    getNextToken();
                }
                if (this.curToken.getType() == TokenType.RPARENT) {
                    getNextToken();
                } else {
                    stmt.setForStmt2(parseForStmt());
                    getNextToken();
                }
                stmt.setForStmt(parseStmt());
            }
        } else if (this.curToken.getType() == TokenType.BREAKTK) {
            getNextToken();
            if (this.curToken.getType() == TokenType.SEMICN) {
                getNextToken();
            } else {
                errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
                System.out.println("Error: i" + getNextToken(-1).getLine());
            }
        } else if (this.curToken.getType() == TokenType.CONTINUETK) {
            getNextToken();
            if (this.curToken.getType() == TokenType.SEMICN) {
                getNextToken();
            } else {
                errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
                System.out.println("Error: i" + getNextToken(-1).getLine());
            }
        } else if (this.curToken.getType() == TokenType.RETURNTK) {
            getNextToken();
            if (this.curToken.getType() != TokenType.SEMICN) {
                stmt.addExp(parseExp());
            }
            if (this.curToken.getType() == TokenType.SEMICN) {
                getNextToken();
            } else {
                errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
                System.out.println("Error: i" + getNextToken(-1).getLine());
            }
        } else if (this.curToken.getType() == TokenType.PRINTFTK) {
            getNextToken();
            if (this.curToken.getType() == TokenType.LPARENT) {
                getNextToken();
                if (this.curToken.getType() == TokenType.STRCON) {
                    getNextToken();
                    while (this.curToken.getType() == TokenType.COMMA) {
                        getNextToken();
                        stmt.addExp(parseExp());
                    }
                    if (this.curToken.getType() == TokenType.RPARENT) {
                        getNextToken();
                        if (this.curToken.getType() == TokenType.SEMICN) {
                            getNextToken();
                        } else {
                            errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
                            System.out.println("Error: i" + getNextToken(-1).getLine());
                        }
                    } else {
                        errors.add(new ErrorInfo('j', getNextToken(-1).getLine()));
                        System.out.println("Error: j" + getNextToken(-1).getLine());
                    }
                }
            }
        } else if (this.curToken.getType() == TokenType.LBRACE) {
            stmt.setBlock(parseBlock());
        } else if (tryParseLVal()) {  //Lval
            stmt.setLVal(parseLVal());
            if (this.curToken.getType() == TokenType.ASSIGN) {
                getNextToken();
                if (this.curToken.getType() == TokenType.GETINTTK || this.curToken.getType() == TokenType.GETCHARTK) {
                    getNextToken();
                    if (this.curToken.getType() == TokenType.LPARENT) {
                        getNextToken();
                        if (this.curToken.getType() == TokenType.RPARENT) {
                            getNextToken();
                            if (this.curToken.getType() == TokenType.SEMICN) {
                                getNextToken();
                            } else {
                                errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
                                System.out.println("Error: i" + getNextToken(-1).getLine());
                            }
                        } else {
                            errors.add(new ErrorInfo('j', getNextToken(-1).getLine()));
                            System.out.println("Error: j" + getNextToken(-1).getLine());
                        }
                    }
                } else {
                    stmt.addExp(parseExp());
                    if (this.curToken.getType() == TokenType.SEMICN) {
                        getNextToken();
                    } else {
                        errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
                        System.out.println("Error: i" + getNextToken(-1).getLine());
                    }
                }
            }
        } else {
//            System.out.println(this.curToken.getType()+"55555");
            if (this.curToken.getType() != TokenType.SEMICN) {
                stmt.addExp(parseExp());
                if (this.curToken.getType() != TokenType.SEMICN) {
                    errors.add(new ErrorInfo('i', getNextToken(-1).getLine()));
                    System.out.println("Error: i" + getNextToken(-1).getLine());
                } else {
                    getNextToken();
                }
            } else {
                getNextToken();
            }
        }
        if (isOutput) {
//        System.out.println("<Stmt>");
            parserWriter.write("<Stmt>\n");
        }
        return stmt;
    }

    // ForStmt → LVal '=' Exp
    public ForStmt parseForStmt() throws IOException {
        ForStmt forStmt = new ForStmt();
        forStmt.setLVal(parseLVal());
        if (this.curToken.getType() == TokenType.ASSIGN) {
            getNextToken();
            forStmt.setExp(parseExp());
        }
        if(isOutput) {
//        System.out.println("<ForStmt>");
        parserWriter.write("<ForStmt>\n");
        }
        return forStmt;
    }

    // Exp → AddExp
    public Exp parseExp() throws IOException {
        Exp exp = new Exp(parseAddExp());
        if (isOutput) {
//        System.out.println("<Exp>");
            parserWriter.write("<Exp>\n");
        }
        return exp;
    }

    // Cond → LOrExp
    public Cond parseCond() throws IOException {
        Cond cond = new Cond(parseLOrExp());
        if (isOutput) {
//        System.out.println("<Cond>");
            parserWriter.write("<Cond>\n");
        }
        return cond;
    }

    // LVal → Ident ['[' Exp ']'] // k
    public LVal parseLVal() throws IOException {
        LVal lVal = new LVal();
        if (this.curToken.getType() == TokenType.IDENFR) {
            lVal.setIdent(this.curToken);
            getNextToken();
            if (this.curToken.getType() == TokenType.LBRACK) {
                getNextToken();
                lVal.setExp(parseExp());
                if (this.curToken.getType() == TokenType.RBRACK) {
                    getNextToken();
                } else {
                    errors.add(new ErrorInfo('k', getNextToken(-1).getLine()));
                    System.out.println("Error: k" + getNextToken(-1).getLine());
                }
            }
        }
        if (isOutput) {
//        System.out.println("<LVal>");
            parserWriter.write("<LVal>\n");
        }
        return lVal;
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
    public PrimaryExp parsePrimaryExp() throws IOException {
        PrimaryExp primaryExp = new PrimaryExp();
        if (this.curToken.getType() == TokenType.LPARENT) {
            getNextToken();
            primaryExp.setExp(parseExp());
            if (this.curToken.getType() == TokenType.RPARENT) {
                getNextToken();
            } else {
                errors.add(new ErrorInfo('j', getNextToken(-1).getLine()));
                System.out.println("Error: j" + getNextToken(-1).getLine());
            }
        } else if (this.curToken.getType() == TokenType.INTCON) {
            primaryExp.setNumber(this.curToken.getValue());
            getNextToken();
            if (isOutput) {
//            System.out.println("<Number>");
                parserWriter.write("<Number>\n");
            }
        } else if (this.curToken.getType() == TokenType.CHRCON) {
            primaryExp.setCharacter(this.curToken.getValue().charAt(0));
            getNextToken();
            if (isOutput) {
//            System.out.println("<Character>");
                parserWriter.write("<Character>\n");
            }
        } else {
            primaryExp.setLVal(parseLVal());
        }
        if (isOutput) {
//        System.out.println("<PrimaryExp>");
            parserWriter.write("<PrimaryExp>\n");
        }
        return primaryExp;
    }

    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    public UnaryExp parseUnaryExp() throws IOException {
        UnaryExp unaryExp = new UnaryExp();
        if (this.curToken.getType() == TokenType.IDENFR && getNextToken(1).getType() == TokenType.LPARENT) {
            unaryExp.setIdent(this.curToken);
            getNextToken();
            if (this.curToken.getType() == TokenType.LPARENT) {
                getNextToken();
                if (this.curToken.getType() != TokenType.RPARENT && this.curToken.getType() != TokenType.SEMICN) {
                    FuncRParams funcRParams = parseFuncRParams();
                    unaryExp.setFuncRParams(funcRParams);
                }
                if (this.curToken.getType() == TokenType.RPARENT) {
                    getNextToken();
                } else {
                    errors.add(new ErrorInfo('j', getNextToken(-1).getLine()));
                    System.out.println("Error: j" + getNextToken(-1).getLine());
                }
            }
        } else if (this.curToken.getType() == TokenType.PLUS || this.curToken.getType() == TokenType.MINU || this.curToken.getType() == TokenType.NOT) {
            UnaryOp unaryOp = parseUnaryOp();
            unaryExp.setUnaryOp(unaryOp);
            unaryExp.setUnaryExp(parseUnaryExp());
        } else {
            unaryExp.setPrimaryExp(parsePrimaryExp());
        }
        if (isOutput) {
//        System.out.println("<UnaryExp>");
            parserWriter.write("<UnaryExp>\n");
        }
        return unaryExp;
    }

    // UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
    public UnaryOp parseUnaryOp() throws IOException {
        UnaryOp unaryOp = new UnaryOp(this.curToken.getType());
        getNextToken();
        if (isOutput) {
//        System.out.println("<UnaryOp>");
            parserWriter.write("<UnaryOp>\n");
        }
        return unaryOp;
    }

    // FuncRParams → Exp { ',' Exp }
    public FuncRParams parseFuncRParams() throws IOException {
        FuncRParams funcRParams = new FuncRParams();
        Exp exp = parseExp();
        funcRParams.addExp(exp);
        while (this.curToken.getType() == TokenType.COMMA) {
            getNextToken();
            exp = parseExp();
            funcRParams.addExp(exp);
        }
        if (isOutput) {
//        System.out.println("<FuncRParams>");
            parserWriter.write("<FuncRParams>\n");
        }
        return funcRParams;
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public MulExp parseMulExp() throws IOException {
        MulExp mulExp = new MulExp();
        mulExp.addUnaryExp(parseUnaryExp());
        if (isOutput) {
//        System.out.println("<MulExp>");
            parserWriter.write("<MulExp>\n");
        }
        while (this.curToken.getType() == TokenType.MULT || this.curToken.getType() == TokenType.DIV || this.curToken.getType() == TokenType.MOD) {
            mulExp.addTokenType(this.curToken.getType());
            getNextToken();
            mulExp.addUnaryExp(parseUnaryExp());
            if (isOutput) {
//            System.out.println("<MulExp>");
                parserWriter.write("<MulExp>\n");
            }
        }
        return mulExp;
    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    public AddExp parseAddExp() throws IOException {
        AddExp addExp = new AddExp();
        addExp.addMulExp(parseMulExp());
        if (isOutput) {
//        System.out.println("<AddExp>");
            parserWriter.write("<AddExp>\n");
        }
        while (this.curToken.getType() == TokenType.PLUS || this.curToken.getType() == TokenType.MINU) {
            addExp.addTokenType(this.curToken.getType());
            getNextToken();
            addExp.addMulExp(parseMulExp());
            if (isOutput) {
//            System.out.println("<AddExp>");
                parserWriter.write("<AddExp>\n");
            }
        }
        return addExp;
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public RelExp parseRelExp() throws IOException {
        RelExp relExp = new RelExp();
        relExp.addAddExp(parseAddExp());
        if (isOutput) {
//        System.out.println("<RelExp>");
            parserWriter.write("<RelExp>\n");
        }
        while (this.curToken.getType() == TokenType.LSS || this.curToken.getType() == TokenType.LEQ || this.curToken.getType() == TokenType.GRE || this.curToken.getType() == TokenType.GEQ) {
            relExp.addTokenType(this.curToken.getType());
            getNextToken();
            relExp.addAddExp(parseAddExp());
            if (isOutput) {
//            System.out.println("<RelExp>");
                parserWriter.write("<RelExp>\n");
            }
        }
        return relExp;
    }

    // EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public EqExp parseEqExp() throws IOException {
        EqExp eqExp = new EqExp();
        eqExp.addRelExp(parseRelExp());
        if (isOutput) {
//        System.out.println("<EqExp>");
            parserWriter.write("<EqExp>\n");
        }
        while (this.curToken.getType() == TokenType.EQL || this.curToken.getType() == TokenType.NEQ) {
            eqExp.addTokenType(this.curToken.getType());
            getNextToken();
            eqExp.addRelExp(parseRelExp());
            if (isOutput) {
//            System.out.println("<EqExp>");
                parserWriter.write("<EqExp>\n");
            }
        }
        return eqExp;
    }

    // LAndExp → EqExp | LAndExp '&&' EqExp
    public LAndExp parseLAndExp() throws IOException {
        LAndExp lAndExp = new LAndExp();
        lAndExp.addEqExp(parseEqExp());
        if (isOutput) {
//        System.out.println("<LAndExp>");
            parserWriter.write("<LAndExp>\n");
        }
        while (this.curToken.getType() == TokenType.AND) {
            getNextToken();
            lAndExp.addEqExp(parseEqExp());
            if (isOutput) {
//            System.out.println("<LAndExp>");
                parserWriter.write("<LAndExp>\n");
            }
        }
        return lAndExp;
    }

    // LOrExp → LAndExp | LOrExp '||' LAndExp
    public LOrExp parseLOrExp() throws IOException {
        LOrExp lOrExp = new LOrExp();
        lOrExp.addLAndExp(parseLAndExp());
        if (isOutput) {
//        System.out.println("<LOrExp>");
            parserWriter.write("<LOrExp>\n");
        }
        while (this.curToken.getType() == TokenType.OR) {
            getNextToken();
            lOrExp.addLAndExp(parseLAndExp());
            if (isOutput) {
//            System.out.println("<LOrExp>");
                parserWriter.write("<LOrExp>\n");
            }
        }
        return lOrExp;
    }

    // ConstExp → AddExp 注：使用的 Ident 必须是常量
    public ConstExp parseConstExp() throws IOException {
        ConstExp constExp = new ConstExp(parseAddExp());
        if (isOutput) {
//        System.out.println("<ConstExp>");
            parserWriter.write("<ConstExp>\n");
        }
        return constExp;
    }
}
