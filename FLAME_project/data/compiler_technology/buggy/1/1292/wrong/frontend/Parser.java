package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Parser {
    private ArrayList<Token> tokens = new ArrayList<>();
    private Token now;
    private int curPos;
    public boolean judge;
    public int precurPos;

    public Parser(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.curPos = 1;
        now = tokens.get(0);
        now.printOut();
        this.judge = true;
    }

    public void next() {
        if (curPos >= tokens.size()) {
            return;
        }
        now = tokens.get(curPos);
        if (judge) now.printOut();
        curPos += 1;
    }

    public Token peek(int step) {
        if (curPos + step - 1 >= tokens.size()) {
            return null;
        }
        return tokens.get(curPos + step - 1);
    }

    public void PRINT(String str) {
        try {
            FileWriter fileWriter = new FileWriter("parser.txt", true);
            fileWriter.write("<" + str + ">\n");
            fileWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void parseCompUnit() {
        while (now.getType() == LexType.CONSTTK ||
                ((now.getType() == LexType.INTTK || now.getType() == LexType.CHARTK) && peek(2).getType() != LexType.LPARENT)) {
            parseDecl();
            next();
        }
        while ((now.getType() == LexType.VOIDTK || now.getType() == LexType.INTTK || now.getType() == LexType.CHARTK)
                && peek(1).getType() != LexType.MAINTK) {
            PRINT("FuncType");
            parseFuncDef();
            next();
        }
        parseMainFuncDef();
        PRINT("CompUnit");
    }

    public void parseDecl() {
        if (now.getType() == LexType.CONSTTK) {
            parseConstDecl();
        } else {
            parseVarDecl();
        }
    }

    public void parseConstDecl() {
        if (now.getType() == LexType.CONSTTK) {
            next();
            if (now.getType() == LexType.INTTK || now.getType() == LexType.CHARTK) {
                next();
                parseConstDef();
                while (peek(1).getType() == LexType.COMMA) {
                    next();
                    next();
                    parseConstDef();
                }
                if (peek(1).getType() != LexType.SEMICN) {
                    Error error = new Error(now.getLineNum(), "i");
                    ErrorList.add(error);
                } else {
                    next();
                }
            }
        }
        PRINT("ConstDecl");
    }

    public void parseConstDef() {
        if (now.getType() == LexType.IDENFR) {
            if (peek(1).getType() == LexType.LBRACK) {
                next();
                next();
                parseConstExp();
                if (peek(1).getType() == LexType.RBRACK) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "k");
                    ErrorList.add(error);
                }
            }
            if (peek(1).getType() == LexType.ASSIGN) {
                next();
                next();
                parseConstInitVal();
            }
        }
        PRINT("ConstDef");
    }

    public void parseVarDecl() {
        if (now.getType() == LexType.INTTK || now.getType() == LexType.CHARTK) {
            next();
            parseVarDef();
            while (peek(1).getType() == LexType.COMMA) {
                next();
                next();
                parseVarDef();
            }
            if (peek(1).getType() == LexType.SEMICN) {
                next();
            } else {
                Error error = new Error(now.getLineNum(), "i");
                ErrorList.add(error);
            }
        }
        PRINT("VarDecl");
    }

    public void parseVarDef() {
        if (now.getType() == LexType.IDENFR) {
            if (peek(1).getType() == LexType.LBRACK) {
                next();
                next();
                parseConstExp();
                if (peek(1).getType() == LexType.RBRACK) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "k");
                    ErrorList.add(error);
                }
            }
            if (peek(1).getType() == LexType.ASSIGN) {
                next();
                next();
                parseInitVal();
            }
        }
        PRINT("VarDef");
    }

    public void parseInitVal() {
        if (now.getType() == LexType.STRCON) {
            PRINT("InitVal");
            return;
        } else if (now.getType() == LexType.LBRACE) {
            if (peek(1).getType() != LexType.RBRACE) {
                next();
                parseExp();
                while (peek(1).getType() == LexType.COMMA) {
                    next();
                    next();
                    parseExp();
                }
                if (peek(1).getType() == LexType.RBRACE) {
                    next();
                }
            } else {
                next();
            }
        } else {
            parseExp();
        }
        PRINT("InitVal");
    }

    public void parseFuncDef() {
        if (now.getType() == LexType.VOIDTK || now.getType() == LexType.INTTK || now.getType() == LexType.CHARTK) {
            next();
            if (now.getType() == LexType.IDENFR) {
                next();
                if (now.getType() == LexType.LPARENT) {
                    if (peek(1).getType() != LexType.RPARENT) {
                        next();
                        parseFuncFParams();
                        if (peek(1).getType() == LexType.RPARENT) {
                            next();
                        } else {
                            Error error = new Error(now.getLineNum(), "j");
                            ErrorList.add(error);
                        }
                    } else {
                        next();
                    }
                    next();
                    parseBlock();
                }
            }
        }
        PRINT("FuncDef");
    }

    public void parseFuncFParams() {
        parseFuncFParam();
        while (peek(1).getType() == LexType.COMMA) {
            next();
            next();
            parseFuncFParam();
        }
        PRINT("FuncFParams");
    }

    public void parseFuncFParam() {
        if (now.getType() == LexType.INTTK || now.getType() == LexType.CHARTK) {
            next();
            if (peek(1).getType() == LexType.LBRACK) {
                next();
                if (peek(1).getType() == LexType.RBRACK) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "k");
                    ErrorList.add(error);
                }
            }
        }
        PRINT("FuncFParam");
    }

    public void parseBlock() {
        if (now.getType() == LexType.LBRACE) {
            if (peek(1).getType() == LexType.RBRACE) {
                next();
            } else {
                while (peek(1).getType() != LexType.RBRACE) {
                    next();
                    parseBlockItem();
                }
                next();
            }
        }
        PRINT("Block");
    }

    public void parseBlockItem() {
        if (now.getType() == LexType.INTTK || now.getType() == LexType.CHARTK) {
            parseDecl();
        } else {
            parseStmt();
        }
    }

    public void parseMainFuncDef() {
        if (now.getType() == LexType.INTTK) {
            next();
            if (now.getType() == LexType.MAINTK) {
                next();
                if (now.getType() == LexType.LPARENT) {
                    if (peek(1).getType() == LexType.RPARENT) {
                        next();
                        next();
                        parseBlock();
                    } else {
                        Error error = new Error(now.getLineNum(), "j");
                        ErrorList.add(error);
                        next();
                        parseBlock();
                    }
                }
            }
        }
        PRINT("MainFuncDef");
    }

    public void parseConstExp() {
        parseAddExp();
        if (judge) PRINT("ConstExp");
    }

    public void parseConstInitVal() {
        if (now.getType() == LexType.STRCON) {
            PRINT("ConstInitVal");
            return;
        } else if (now.getType() == LexType.LBRACE) {
            if (peek(1).getType() != LexType.RBRACE) {
                next();
                parseConstExp();
                while (peek(1).getType() == LexType.COMMA) {
                    next();
                    next();
                    parseConstExp();
                }
                if (peek(1).getType() == LexType.RBRACE) {
                    next();
                }
            } else {
                next();
            }
        } else {
            parseConstExp();
        }
        PRINT("ConstInitVal");
    }

    public void parseExp() {
        parseAddExp();
        if (judge) PRINT("Exp");
    }

    public void parsePrimaryExp() {
        if (now.getType() == LexType.LPARENT) {
            next();
            parseExp();
            if (peek(1).getType() == LexType.RPARENT) {
                next();
            } else if (judge) {
                Error error = new Error(now.getLineNum(), "j");
                ErrorList.add(error);
            }
        } else if (now.getType() == LexType.INTCON) {
            parseNumber();
        } else if (now.getType() == LexType.CHRCON) {
            parseCharacter();
        } else {
            parseLVal();
        }
        if (judge) PRINT("PrimaryExp");
    }

    public void parseNumber() {
        if (judge) PRINT("Number");
    }

    public void parseCharacter() {
        if (judge) PRINT("Character");
    }

    public void parseAddExp() {
        parseMulExp();
        if (judge) PRINT("AddExp");
        while (peek(1).getType() == LexType.PLUS || peek(1).getType() == LexType.MINU) {
            next();
            next();
            parseMulExp();
            if (judge) PRINT("AddExp");
        }
    }

    public void parseCond() {
        parseLOrExp();
        if (judge) PRINT("Cond");
    }

    public void parseLVal() {
        if (now.getType() == LexType.IDENFR) {
            if (peek(1).getType() == LexType.LBRACK) {
                next();
                next();
                parseExp();
                if (peek(1).getType() == LexType.RBRACK) {
                    next();
                } else if (judge) {
                    Error error = new Error(now.getLineNum(), "k");
                    ErrorList.add(error);
                }
            }
        }
        if (judge) PRINT("LVal");
    }

    public void parseUnaryExp() {
        if (now.getType() == LexType.PLUS || now.getType() == LexType.MINU || now.getType() == LexType.NOT) {
            parseUnaryOp();
            next();
            parseUnaryExp();
        } else if (now.getType() == LexType.IDENFR && peek(1).getType() == LexType.LPARENT) {
            next();
            if (peek(1).getType() == LexType.RPARENT) {
                next();
            } else {
                next();
                parseFuncRParams();
                if (peek(1).getType() == LexType.RPARENT) {
                    next();
                } else if (judge) {
                    Error error = new Error(now.getLineNum(), "j");
                    ErrorList.add(error);
                }
            }
        } else {
            parsePrimaryExp();
        }
        if (judge) PRINT("UnaryExp");
    }

    public void parseUnaryOp() {
        if(judge) PRINT("UnaryOp");
    }

    public void parseFuncRParams() {
        parseExp();
        while (peek(1).getType() == LexType.COMMA) {
            next();
            next();
            parseExp();
        }
        if (judge) PRINT("FuncRParams");
    }

    public void parseMulExp() {
        parseUnaryExp();
        if (judge) PRINT("MulExp");
        while (peek(1).getType() == LexType.MULT || peek(1).getType() == LexType.DIV || peek(1).getType() == LexType.MOD) {
            next();
            next();
            parseUnaryExp();
            if (judge) PRINT("MulExp");
        }
    }

    public void parseRelExp() {
        parseAddExp();
        if (judge) PRINT("RelExp");
        while (peek(1).getType() == LexType.LSS || peek(1).getType() == LexType.LEQ
                || peek(1).getType() == LexType.GRE || peek(1).getType() == LexType.GEQ) {
            next();
            next();
            parseAddExp();
            if (judge) PRINT("RelExp");
        }
    }

    public void parseEqExp() {
        parseRelExp();
        if (judge) PRINT("EqExp");
        while (peek(1).getType() == LexType.EQL || peek(1).getType() == LexType.NEQ) {
            next();
            next();
            parseRelExp();
            if (judge) PRINT("EqExp");
        }
    }

    public void parseLAndExp() {
        parseEqExp();
        if (judge) PRINT("LAndExp");
        while (peek(1).getType() == LexType.AND) {
            next();
            next();
            parseEqExp();
            if (judge) PRINT("LAndExp");
        }
    }

    public void parseLOrExp() {
        parseLAndExp();
        if (judge) PRINT("LOrExp");
        while (peek(1).getType() == LexType.OR) {
            next();
            next();
            parseLAndExp();
            if (judge) PRINT("LOrExp");
        }
    }

    public void parseStmt() {
        if (now.getType() == LexType.LBRACE) {
            parseBlock();
        } else if (now.getType() == LexType.IFTK) {
            if (peek(1).getType() == LexType.LPARENT) {
                next();
                next();
                parseCond();
                if (peek(1).getType() != LexType.RPARENT) {
                    Error error = new Error(now.getLineNum(), "j");
                    ErrorList.add(error);
                } else {
                    next();
                }
                next();
                parseStmt();
                if (peek(1).getType() == LexType.ELSETK) {
                    next();
                    next();
                    parseStmt();
                }
            }
        } else if (now.getType() == LexType.FORTK) {
            if (peek(1).getType() == LexType.LPARENT) {
                next();
                if (peek(1).getType() != LexType.SEMICN) {
                    next();
                    parseForStmt();
                }
                next();
                if (peek(1).getType() != LexType.SEMICN) {
                    next();
                    parseCond();
                }
                next();
                if (peek(1).getType() != LexType.RPARENT) {
                    next();
                    parseForStmt();
                }
                next();
                next();
                parseStmt();
            }
        } else if (now.getType() == LexType.BREAKTK || now.getType() == LexType.CONTINUETK) {
            if (peek(1).getType() == LexType.SEMICN) {
                next();
            } else {
                Error error = new Error(now.getLineNum(), "i");
                ErrorList.add(error);
            }
        } else if (now.getType() == LexType.RETURNTK) {
            if (peek(1).getType() == LexType.INTCON
                    || peek(1).getType() == LexType.CHRCON || peek(1).getType() == LexType.LPARENT
                    || peek(1).getType() == LexType.PLUS || peek(1).getType() == LexType.MINU
                    || peek(1).getType() == LexType.NOT) {
                next();
                parseExp();
                if (peek(1).getType() == LexType.SEMICN) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "i");
                    ErrorList.add(error);
                }
            } else if (peek(1).getType() == LexType.IDENFR) {
                next();
                judge = false;
                precurPos = curPos;
                parseLVal();
                if (peek(1).getType() == LexType.ASSIGN) {
                    Error error = new Error(tokens.get(precurPos - 1).getLineNum(), "i");
                    ErrorList.add(error);
                    judge = true;
                    curPos = precurPos;
                    now = tokens.get(curPos - 1);
                } else {
                    judge = true;
                    curPos = precurPos;
                    now = tokens.get(curPos - 1);
                    parseExp();
                    if (peek(1).getType() == LexType.SEMICN) {
                        next();
                    } else {
                        Error error = new Error(now.getLineNum(), "i");
                        ErrorList.add(error);
                    }
                }
            } else {
                if (peek(1).getType() == LexType.SEMICN) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "i");
                    ErrorList.add(error);
                }
            }
        } else if (now.getType() == LexType.PRINTFTK) {
            if (peek(1).getType() == LexType.LPARENT) {
                next();
                next();
                while (peek(1).getType() == LexType.COMMA) {
                    next();
                    next();
                    parseExp();
                }
                if (peek(1).getType() == LexType.RPARENT) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "j");
                    ErrorList.add(error);
                }
                if (peek(1).getType() == LexType.SEMICN) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "i");
                    ErrorList.add(error);
                }
            }
        } else if (now.getType() == LexType.IDENFR) {
            judge = false;
            precurPos = curPos;
            parseLVal();
            int isClass = isLValeq();
            judge = true;
            curPos = precurPos;
            now = tokens.get(precurPos - 1);
            if (isClass == 0) {
                parseExp();
                if (peek(1).getType() == LexType.SEMICN) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "i");
                    ErrorList.add(error);
                }
            } else if (isClass == 1 || isClass == 2) {
                parseLVal();
                next();
                next();
                if (peek(1).getType() == LexType.LPARENT) {
                    next();
                    if (peek(1).getType() == LexType.RPARENT) {
                        next();
                    } else {
                        Error error = new Error(now.getLineNum(), "j");
                        ErrorList.add(error);
                    }
                    if (peek(1).getType() == LexType.SEMICN) {
                        next();
                    } else {
                        Error error = new Error(now.getLineNum(), "i");
                        ErrorList.add(error);
                    }
                }
            } else {
                parseLVal();
                next();
                next();
                parseExp();
                if (peek(1).getType() == LexType.SEMICN) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "i");
                    ErrorList.add(error);
                }
            }
        } else {
            if (now.getType() == LexType.SEMICN) {
            } else {
                parseExp();
                if (peek(1).getType() == LexType.SEMICN) {
                    next();
                } else {
                    Error error = new Error(now.getLineNum(), "i");
                    ErrorList.add(error);
                }
            }
        }
        PRINT("Stmt");
    }

    public void parseForStmt() {
        parseLVal();
        if (peek(1).getType() == LexType.ASSIGN) {
            next();
            next();
            parseExp();
        }
        PRINT("ForStmt");
    }

    public int isLValeq() {
        if (peek(1).getType() != LexType.ASSIGN) {
            return 0;
        } else if (peek(2).getType() == LexType.GETINTTK) {
            return 1;
        } else if (peek(2).getType() == LexType.GETCHARTK) {
            return 2;
        } else {
            return 3;
        }
    }
}
