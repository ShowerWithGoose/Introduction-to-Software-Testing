package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.util.ArrayList;

public class Stmt {
    public enum StmtType {
        LVALEXP, EXP, BLOCK, IFSTMT, FORSTMT,
        BREAKSTMT, CONTINUESTMT, RETURNSTMT,
        LVALGETINT, LVALGETCHAR, PRINTSTMT
    }

    private LVal expLVal;
    private Token expAssign;
    private Exp lValExp;

    private Exp exp;

    private Block block;

    private Token iftk;
    private Token ifLparent;
    private Cond ifCond;
    private Token ifRparent;
    private Stmt ifStmt;
    private Token elsetk;
    private Stmt elseStmt;

    private Token fortk;
    private Token forLparent;
    private ForStmt firstForStmt;
    private Token firstSemicn;
    private Cond forCond;
    private Token lastSemicn;
    private ForStmt lastForStmt;
    private Token forRparent;
    private Stmt forStmt;

    private Token breaktk;

    private Token continuetk;

    private Token returnk;
    private Exp returnExp;

    private LVal getintLVal;
    private Token getintAssign;
    private Token getinttk;

    private LVal getcharLVal;
    private Token getcharAssign;
    private Token getchartk;

    private Token printftk;

    private Token inOrOutLparent;
    private Token strcon;
    private ArrayList<Token> commas;
    private ArrayList<Exp> printExps;
    private Token inOrOutRparent;

    private Token semicn;

    private StmtType stmtType;
    private int lineCnt;

    public Stmt() {
        expLVal = null;
        expAssign = null;
        lValExp = null;
        exp = null;
        block = null;
        iftk = null;
        ifLparent = null;
        ifCond = null;
        ifRparent = null;
        ifStmt = null;
        elsetk = null;
        elseStmt = null;
        fortk = null;
        forLparent = null;
        firstForStmt = null;
        firstSemicn = null;
        forCond = null;
        lastSemicn = null;
        lastForStmt = null;
        forRparent = null;
        forStmt = null;
        breaktk = null;
        continuetk = null;
        returnk = null;
        returnExp = null;
        getintLVal = null;
        getintAssign = null;
        getinttk = null;
        getcharLVal = null;
        getcharAssign = null;
        getchartk = null;
        printftk = null;
        inOrOutLparent = null;
        strcon = null;
        commas = new ArrayList<>();
        printExps = new ArrayList<>();
        inOrOutRparent = null;
        semicn = null;
        stmtType = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        Token.Type nowType = lexer.now().getType();
        if (nowType == Token.Type.LBRACE) {
            stmtType = StmtType.BLOCK;
            block = new Block();
            block.parser(lexer, errors);
            lineCnt = block.getLineCnt();
        } else if (nowType == Token.Type.IFTK) {
            stmtType = StmtType.IFSTMT;
            ifStmtParser(lexer, errors);
        } else if (nowType == Token.Type.FORTK) {
            stmtType = StmtType.FORSTMT;
            forStmtParser(lexer, errors);
        } else if (nowType == Token.Type.BREAKTK) {
            stmtType = StmtType.BREAKSTMT;
            breaktk = lexer.now();
            lexer.move();
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                errors.add(breaktk.getLineCnt() + " i");
            }
            lineCnt = breaktk.getLineCnt();
        } else if (nowType == Token.Type.CONTINUETK) {
            stmtType = StmtType.CONTINUESTMT;
            continuetk = lexer.now();
            lexer.move();
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                errors.add(continuetk.getLineCnt() + " i");
            }
            lineCnt = continuetk.getLineCnt();
        } else if (nowType == Token.Type.RETURNTK) {
            stmtType = StmtType.RETURNSTMT;
            returnk = lexer.now();
            lexer.move();
            if (lexer.now().getType() == Token.Type.PLUS ||
                    lexer.now().getType() == Token.Type.MINU ||
                    lexer.now().getType() == Token.Type.NOT ||
                    lexer.now().getType() == Token.Type.IDENFR ||
                    lexer.now().getType() == Token.Type.LPARENT ||
                    lexer.now().getType() == Token.Type.INTCON ||
                    lexer.now().getType() == Token.Type.CHRCON) {
                returnExp = new Exp();
                returnExp.parser(lexer, errors);
            }
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                if (returnExp == null) {
                    errors.add(returnk.getLineCnt() + " i");
                } else {
                    errors.add(returnExp.getLineCnt() + " i");
                }
            }
            lineCnt = returnk.getLineCnt();
        } else if (nowType == Token.Type.PRINTFTK) {
            stmtType = StmtType.PRINTSTMT;
            printftk = lexer.now();
            lexer.move();
            inOrOutLparent = lexer.now();
            lexer.move();
            strcon = lexer.now();
            lexer.move();
            while (lexer.now().getType() == Token.Type.COMMA) {
                Token comma = lexer.now();
                lexer.move();
                commas.add(comma);
                Exp printExp = new Exp();
                printExp.parser(lexer, errors);
                printExps.add(printExp);
            }
            if (lexer.now().getType() == Token.Type.RPARENT) {
                inOrOutRparent = lexer.now();
                lexer.move();
            } else {
                if (printExps.isEmpty()) {
                    errors.add(strcon.getLineCnt() + " j");
                } else {
                    int last = printExps.size() - 1;
                    errors.add(printExps.get(last).getLineCnt() + " j");
                }
            }
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                if (inOrOutRparent == null) {
                    if (printExps.isEmpty()) {
                        errors.add(strcon.getLineCnt() + " i");
                    } else {
                        int last = printExps.size() - 1;
                        errors.add(printExps.get(last).getLineCnt() + " i");
                    }
                } else {
                    errors.add(inOrOutRparent.getLineCnt() + " i");
                }
            }
            lineCnt = printftk.getLineCnt();
        } else if (nowType == Token.Type.IDENFR) {
            int des = lexer.getCur();
            lexer.move();
            if (lexer.now().getType() == Token.Type.ASSIGN) {
                lexer.move();
                if (lexer.now().getType() == Token.Type.GETINTTK) {
                    stmtType = StmtType.LVALGETINT;
                    lexer.back();
                    lexer.back();
                    getintStmt(lexer, errors);
                } else if (lexer.now().getType() == Token.Type.GETCHARTK) {
                    stmtType = StmtType.LVALGETCHAR;
                    lexer.back();
                    lexer.back();
                    getcharStmt(lexer, errors);
                } else {
                    stmtType = StmtType.LVALEXP;
                    lexer.back();
                    lexer.back();
                    lValExpStmt(lexer, errors);
                }
            } else if (lexer.now().getType() == Token.Type.LBRACK) {
                lexer.move();
                Exp tempExp = new Exp();
                tempExp.parser(lexer, errors);
                if (lexer.now().getType() == Token.Type.RBRACK) {
                    lexer.move();
                }
//                Token tempRBrack = lexer.now();
//                lexer.move();
                if (lexer.now().getType() == Token.Type.ASSIGN) {
                    lexer.move();
                    if (lexer.now().getType() == Token.Type.GETINTTK) {
                        stmtType = StmtType.LVALGETINT;
                        lexer.jump(des);
                        getintStmt(lexer, errors);
                    } else if (lexer.now().getType() == Token.Type.GETCHARTK) {
                        stmtType = StmtType.LVALGETCHAR;
                        lexer.jump(des);
                        getcharStmt(lexer, errors);
                    } else {
                        stmtType = StmtType.LVALEXP;
                        lexer.jump(des);
                        lValExpStmt(lexer, errors);
                    }
                } else {
                    lexer.jump(des);
                    exp = new Exp();
                    exp.parser(lexer, errors);
                    if (lexer.now().getType() == Token.Type.SEMICN) {
                        semicn = lexer.now();
                        lexer.move();
                    } else {
                        errors.add(exp.getLineCnt() + " i");
                    }
                    lineCnt = exp.getLineCnt();
                }
            } else {
                lexer.jump(des);
                exp = new Exp();
                exp.parser(lexer, errors);
                if (lexer.now().getType() == Token.Type.SEMICN) {
                    semicn = lexer.now();
                    lexer.move();
                } else {
                    errors.add(exp.getLineCnt() + " i");
                }
                lineCnt = exp.getLineCnt();
            }
        } else if (nowType == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
            lineCnt = semicn.getLineCnt();
        } else {
            exp = new Exp();
            exp.parser(lexer, errors);
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                errors.add(exp.getLineCnt() + " i");
            }
            lineCnt = exp.getLineCnt();
        }
    }
    
    private void ifStmtParser(Lexer lexer, ArrayList<String> errors) {
        iftk = lexer.now();
        lexer.move();
        ifLparent = lexer.now();
        lexer.move();
        ifCond = new Cond();
        ifCond.parser(lexer, errors);
        if (lexer.now().getType() == Token.Type.RPARENT) {
            ifRparent = lexer.now();
            lexer.move();
        } else {
            errors.add(ifCond.getLineCnt() + " j");
        }
        ifStmt = new Stmt();
        ifStmt.parser(lexer, errors);
        if (lexer.now().getType() == Token.Type.ELSETK) {
            elsetk = lexer.now();
            lexer.move();
            elseStmt = new Stmt();
            elseStmt.parser(lexer, errors);
        }
        lineCnt = iftk.getLineCnt();
    }
    
    private void forStmtParser(Lexer lexer, ArrayList<String> errors) {
        fortk = lexer.now();
        lexer.move();
        forLparent = lexer.now();
        lexer.move();
        if (lexer.now().getType() != Token.Type.SEMICN) {
            firstForStmt = new ForStmt();
            firstForStmt.parser(lexer, errors);
        }
        firstSemicn = lexer.now();
        lexer.move();
        if (lexer.now().getType() != Token.Type.SEMICN) {
            forCond = new Cond();
            forCond.parser(lexer, errors);
        }
        lastSemicn = lexer.now();
        lexer.move();
        if (lexer.now().getType() != Token.Type.RPARENT) {
            lastForStmt = new ForStmt();
            lastForStmt.parser(lexer, errors);
        }
        forRparent = lexer.now();
        lexer.move();
        forStmt = new Stmt();
        forStmt.parser(lexer, errors);
        lineCnt = fortk.getLineCnt();
    }

    private void getintStmt(Lexer lexer, ArrayList<String> errors) {
        getintLVal = new LVal();
        getintLVal.parser(lexer, errors);
        getintAssign = lexer.now();
        lexer.move();
        getinttk = lexer.now();
        lexer.move();
        inOrOutLparent = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.RPARENT) {
            inOrOutRparent = lexer.now();
            lexer.move();
        } else {
            errors.add(inOrOutLparent.getLineCnt() + " j");
        }
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            if (inOrOutRparent == null) {
                errors.add(inOrOutLparent.getLineCnt() + " i");
            } else {
                errors.add(inOrOutRparent.getLineCnt() + " i");
            }
        }
        lineCnt = getintLVal.getLineCnt();
    }

    private void getcharStmt(Lexer lexer, ArrayList<String> errors) {
        getcharLVal = new LVal();
        getcharLVal.parser(lexer, errors);
        getcharAssign = lexer.now();
        lexer.move();
        getchartk = lexer.now();
        lexer.move();
        inOrOutLparent = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.RPARENT) {
            inOrOutRparent = lexer.now();
            lexer.move();
        } else {
            errors.add(inOrOutLparent.getLineCnt() + " j");
        }
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            if (inOrOutRparent == null) {
                errors.add(inOrOutLparent.getLineCnt() + " i");
            } else {
                errors.add(inOrOutRparent.getLineCnt() + " i");
            }
        }
        lineCnt = getcharLVal.getLineCnt();
    }

    private void lValExpStmt(Lexer lexer, ArrayList<String> errors) {
        expLVal = new LVal();
        expLVal.parser(lexer, errors);
        expAssign = lexer.now();
        lexer.move();
        lValExp = new Exp();
        lValExp.parser(lexer, errors);
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            errors.add(lValExp.getLineCnt() + " i");
        }
        lineCnt = expLVal.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        if (expLVal != null) {
            expLVal.output(parserResult);
        }
        if (expAssign != null) {
            parserResult.add(expAssign.getType().toString() + " " + expAssign.getContent());
        }
        if (lValExp != null) {
            lValExp.output(parserResult);
        }
        if (exp != null) {
            exp.output(parserResult);
        }
        if (block != null) {
            block.output(parserResult);
        }
        if (iftk != null) {
            parserResult.add(iftk.getType().toString() + " " + iftk.getContent());
        }
        if (ifLparent != null) {
            parserResult.add(ifLparent.getType().toString() + " " + ifLparent.getContent());
        }
        if (ifCond != null) {
            ifCond.output(parserResult);
        }
        if (ifRparent != null) {
            parserResult.add(ifRparent.getType().toString() + " " + ifRparent.getContent());
        }
        if (ifStmt != null) {
            ifStmt.output(parserResult);
        }
        if (elsetk != null) {
            parserResult.add(elsetk.getType().toString() + " " + elsetk.getContent());
        }
        if (elseStmt != null) {
            elseStmt.output(parserResult);
        }
        if (fortk != null) {
            parserResult.add(fortk.getType().toString() + " " + fortk.getContent());
        }
        if (forLparent != null) {
            parserResult.add(forLparent.getType().toString() + " " + forLparent.getContent());
        }
        if (firstForStmt != null) {
            firstForStmt.output(parserResult);
        }
        if (firstSemicn != null) {
            parserResult.add(firstSemicn.getType().toString() + " " + firstSemicn.getContent());
        }
        if (forCond != null) {
            forCond.output(parserResult);
        }
        if (lastSemicn != null) {
            parserResult.add(lastSemicn.getType().toString() + " " + lastSemicn.getContent());
        }
        if (lastForStmt != null) {
            lastForStmt.output(parserResult);
        }
        if (forRparent != null) {
            parserResult.add(forRparent.getType().toString() + " " + forRparent.getContent());
        }
        if (forStmt != null) {
            forStmt.output(parserResult);
        }
        if (breaktk != null) {
            parserResult.add(breaktk.getType().toString() + " " + breaktk.getContent());
        }
        if (continuetk != null) {
            parserResult.add(continuetk.getType().toString() + " " + continuetk.getContent());
        }
        if (returnk != null) {
            parserResult.add(returnk.getType().toString() + " " + returnk.getContent());
        }
        if (returnExp != null) {
            returnExp.output(parserResult);
        }
        if (getintLVal != null) {
            getintLVal.output(parserResult);
        }
        if (getintAssign != null) {
            parserResult.add(getintAssign.getType().toString() + " " + getintAssign.getContent());
        }
        if (getinttk != null) {
            parserResult.add(getinttk.getType().toString() + " " + getinttk.getContent());
        }
        if (getcharLVal != null) {
            getcharLVal.output(parserResult);
        }
        if (getcharAssign != null) {
            parserResult.add(getcharAssign.getType().toString() + " " + getcharAssign.getContent());
        }
        if (getchartk != null) {
            parserResult.add(getchartk.getType().toString() + " " + getchartk.getContent());
        }
        if (printftk != null) {
            parserResult.add(printftk.getType().toString() + " " + printftk.getContent());
        }
        if (inOrOutLparent != null) {
            parserResult.add(inOrOutLparent.getType().toString() + " " + inOrOutLparent.getContent());
        }
        if (strcon != null) {
            parserResult.add(strcon.getType().toString() + " " + strcon.getContent());
        }
        for (int i = 0; i < printExps.size(); i++) {
            parserResult.add(commas.get(i).getType().toString() + " " + commas.get(i).getContent());
            printExps.get(i).output(parserResult);
        }
        if (inOrOutRparent != null) {
            parserResult.add(inOrOutRparent.getType().toString() + " " + inOrOutRparent.getContent());
        }
        if (semicn != null) {
            parserResult.add(semicn.getType().toString() + " " + semicn.getContent());
        }
        parserResult.add("<Stmt>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}