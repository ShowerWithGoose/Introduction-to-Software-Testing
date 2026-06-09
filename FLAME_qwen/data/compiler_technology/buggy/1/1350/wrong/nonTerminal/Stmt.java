package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
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

    public void parser(Lexer lexer) {
        Token.Type nowType = lexer.now().getType();
        if (nowType == Token.Type.LBRACE) {
            stmtType = StmtType.BLOCK;
            block = new Block();
            block.parser(lexer);
            lineCnt = block.getLineCnt();
        } else if (nowType == Token.Type.IFTK) {
            stmtType = StmtType.IFSTMT;
            ifStmtParser(lexer);
        } else if (nowType == Token.Type.FORTK) {
            stmtType = StmtType.FORSTMT;
            forStmtParser(lexer);
        } else if (nowType == Token.Type.BREAKTK) {
            stmtType = StmtType.BREAKSTMT;
            breaktk = lexer.now();
            lexer.move();
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                semicn = new Token(Token.Type.SEMICN, ";", breaktk.getLineCnt());
                semicn.setIsCorrect(false);
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
                semicn = new Token(Token.Type.SEMICN, ";", continuetk.getLineCnt());
                semicn.setIsCorrect(false);
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
                returnExp.parser(lexer);
            }
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                if (returnExp == null) {
                    semicn = new Token(Token.Type.SEMICN, ";", returnk.getLineCnt());
                } else {
                    semicn = new Token(Token.Type.SEMICN, ";", returnExp.getLineCnt());
                }
                semicn.setIsCorrect(false);
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
                printExp.parser(lexer);
                printExps.add(printExp);
            }
            if (lexer.now().getType() == Token.Type.RPARENT) {
                inOrOutRparent = lexer.now();
                lexer.move();
            } else {
                if (printExps.isEmpty()) {
                    inOrOutRparent = new Token(Token.Type.RPARENT, ")", strcon.getLineCnt());
                } else {
                    int last = printExps.size() - 1;
                    inOrOutRparent = new Token(Token.Type.RPARENT, ")", printExps.get(last).getLineCnt());
                }
                inOrOutRparent.setIsCorrect(false);
            }
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                if (inOrOutRparent == null) {
                    if (printExps.isEmpty()) {
                        semicn = new Token(Token.Type.SEMICN, ";", strcon.getLineCnt());
                    } else {
                        int last = printExps.size() - 1;
                        semicn = new Token(Token.Type.SEMICN, ";", printExps.get(last).getLineCnt());
                    }
                } else {
                    semicn = new Token(Token.Type.SEMICN, ";", inOrOutRparent.getLineCnt());
                }
                semicn.setIsCorrect(false);
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
                    getintStmt(lexer);
                } else if (lexer.now().getType() == Token.Type.GETCHARTK) {
                    stmtType = StmtType.LVALGETCHAR;
                    lexer.back();
                    lexer.back();
                    getcharStmt(lexer);
                } else {
                    stmtType = StmtType.LVALEXP;
                    lexer.back();
                    lexer.back();
                    lValExpStmt(lexer);
                }
            } else if (lexer.now().getType() == Token.Type.LBRACK) {
                lexer.move();
                Exp tempExp = new Exp();
                tempExp.parser(lexer);
                if (lexer.now().getType() == Token.Type.RBRACK) {
                    lexer.move();
                }
                if (lexer.now().getType() == Token.Type.ASSIGN) {
                    lexer.move();
                    if (lexer.now().getType() == Token.Type.GETINTTK) {
                        stmtType = StmtType.LVALGETINT;
                        lexer.jump(des);
                        getintStmt(lexer);
                    } else if (lexer.now().getType() == Token.Type.GETCHARTK) {
                        stmtType = StmtType.LVALGETCHAR;
                        lexer.jump(des);
                        getcharStmt(lexer);
                    } else {
                        stmtType = StmtType.LVALEXP;
                        lexer.jump(des);
                        lValExpStmt(lexer);
                    }
                } else {
                    lexer.jump(des);
                    stmtType = StmtType.EXP;
                    exp = new Exp();
                    exp.parser(lexer);
                    if (lexer.now().getType() == Token.Type.SEMICN) {
                        semicn = lexer.now();
                        lexer.move();
                    } else {
                        semicn = new Token(Token.Type.SEMICN, ";", exp.getLineCnt());
                        semicn.setIsCorrect(false);
                    }
                    lineCnt = exp.getLineCnt();
                }
            } else {
                lexer.jump(des);
                stmtType = StmtType.EXP;
                exp = new Exp();
                exp.parser(lexer);
                if (lexer.now().getType() == Token.Type.SEMICN) {
                    semicn = lexer.now();
                    lexer.move();
                } else {
                    semicn = new Token(Token.Type.SEMICN, ";", exp.getLineCnt());
                    semicn.setIsCorrect(false);
                }
                lineCnt = exp.getLineCnt();
            }
        } else if (nowType == Token.Type.SEMICN) {
            stmtType = StmtType.EXP;
            semicn = lexer.now();
            lexer.move();
            lineCnt = semicn.getLineCnt();
        } else {
            stmtType = StmtType.EXP;
            exp = new Exp();
            exp.parser(lexer);
            if (lexer.now().getType() == Token.Type.SEMICN) {
                semicn = lexer.now();
                lexer.move();
            } else {
                semicn = new Token(Token.Type.SEMICN, ";", exp.getLineCnt());
                semicn.setIsCorrect(false);
            }
            lineCnt = exp.getLineCnt();
        }
    }
    
    private void ifStmtParser(Lexer lexer) {
        iftk = lexer.now();
        lexer.move();
        ifLparent = lexer.now();
        lexer.move();
        ifCond = new Cond();
        ifCond.parser(lexer);
        if (lexer.now().getType() == Token.Type.RPARENT) {
            ifRparent = lexer.now();
            lexer.move();
        } else {
            ifRparent = new Token(Token.Type.RPARENT, ")", ifCond.getLineCnt());
            ifRparent.setIsCorrect(false);
        }
        ifStmt = new Stmt();
        ifStmt.parser(lexer);
        if (lexer.now().getType() == Token.Type.ELSETK) {
            elsetk = lexer.now();
            lexer.move();
            elseStmt = new Stmt();
            elseStmt.parser(lexer);
        }
        lineCnt = iftk.getLineCnt();
    }
    
    private void forStmtParser(Lexer lexer) {
        fortk = lexer.now();
        lexer.move();
        forLparent = lexer.now();
        lexer.move();
        if (lexer.now().getType() != Token.Type.SEMICN) {
            firstForStmt = new ForStmt();
            firstForStmt.parser(lexer);
        }
        firstSemicn = lexer.now();
        lexer.move();
        if (lexer.now().getType() != Token.Type.SEMICN) {
            forCond = new Cond();
            forCond.parser(lexer);
        }
        lastSemicn = lexer.now();
        lexer.move();
        if (lexer.now().getType() != Token.Type.RPARENT) {
            lastForStmt = new ForStmt();
            lastForStmt.parser(lexer);
        }
        forRparent = lexer.now();
        lexer.move();
        forStmt = new Stmt();
        forStmt.parser(lexer);
        lineCnt = fortk.getLineCnt();
    }

    private void getintStmt(Lexer lexer) {
        getintLVal = new LVal();
        getintLVal.parser(lexer);
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
            inOrOutRparent = new Token(Token.Type.RPARENT, ")", inOrOutLparent.getLineCnt());
            inOrOutRparent.setIsCorrect(false);
        }
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            if (inOrOutRparent == null) {
                semicn = new Token(Token.Type.SEMICN, ";", inOrOutLparent.getLineCnt());
            } else {
                semicn = new Token(Token.Type.SEMICN, ";", inOrOutRparent.getLineCnt());
            }
            semicn.setIsCorrect(false);
        }
        lineCnt = getintLVal.getLineCnt();
    }

    private void getcharStmt(Lexer lexer) {
        getcharLVal = new LVal();
        getcharLVal.parser(lexer);
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
            inOrOutRparent = new Token(Token.Type.RPARENT, ")", inOrOutLparent.getLineCnt());
            inOrOutRparent.setIsCorrect(false);
        }
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            semicn = new Token(Token.Type.SEMICN, ";", inOrOutRparent.getLineCnt());
            semicn.setIsCorrect(false);
        }
        lineCnt = getcharLVal.getLineCnt();
    }

    private void lValExpStmt(Lexer lexer) {
        expLVal = new LVal();
        expLVal.parser(lexer);
        expAssign = lexer.now();
        lexer.move();
        lValExp = new Exp();
        lValExp.parser(lexer);
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            semicn = new Token(Token.Type.SEMICN, ";", lValExp.getLineCnt());
            semicn.setIsCorrect(false);
        }
        lineCnt = expLVal.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (stmtType == StmtType.LVALEXP) {
            expLVal.analyze(symbolTable);
            String type = symbolTable.getType(expLVal.getIdentifier().getContent());
            if (type != null) {
                if (type.equals("ConstInt") || type.equals("ConstChar") ||
                        type.equals("ConstCharArray") || type.equals("ConstIntArray")) {
                    symbolTable.addError(expLVal.getLineCnt() + " h");
                }
            }
            lValExp.analyze(symbolTable);
            if (!semicn.getIsCorrect()) {
                symbolTable.addError(semicn.getLineCnt() + " i");
            }
        } else if (stmtType == StmtType.EXP) {
            if (exp != null) {
                exp.analyze(symbolTable);
            }
            if (!semicn.getIsCorrect()) {
                symbolTable.addError(semicn.getLineCnt() + " i");
            }
        } else if (stmtType == StmtType.BLOCK) {
            block.analyze(symbolTable);
        } else if (stmtType == StmtType.IFSTMT) {
            ifCond.analyze(symbolTable);
            if (!ifRparent.getIsCorrect()) {
                symbolTable.addError(ifRparent.getLineCnt() + " j");
            }
            ifStmt.analyze(symbolTable);
            if (elseStmt != null) {
                elseStmt.analyze(symbolTable);
            }
        } else if (stmtType == StmtType.FORSTMT) {
            symbolTable.addCircleCnt();
            if (firstForStmt != null) {
                firstForStmt.analyze(symbolTable);
            }
            if (forCond != null) {
                forCond.analyze(symbolTable);
            }
            if (lastForStmt != null) {
                lastForStmt.analyze(symbolTable);
            }
            forStmt.analyze(symbolTable);
            symbolTable.subCircleCnt();
        } else if (stmtType == StmtType.BREAKSTMT) {
            if (symbolTable.getCircleCnt() == 0) {
                symbolTable.addError(breaktk.getLineCnt() + " m");
            }
            if (!semicn.getIsCorrect()) {
                symbolTable.addError(semicn.getLineCnt() + " i");
            }
        } else if (stmtType == StmtType.CONTINUESTMT) {
            if (symbolTable.getCircleCnt() == 0) {
                symbolTable.addError(continuetk.getLineCnt() + " m");
            }
            if (!semicn.getIsCorrect()) {
                symbolTable.addError(semicn.getLineCnt() + " i");
            }
        } else if (stmtType == StmtType.RETURNSTMT) {
            if (returnExp != null && symbolTable.getReturnFuncType() == SymbolTable.ReturnFuncType.VOID) {
                symbolTable.addError(returnk.getLineCnt() + " f");
            } else if (returnExp != null && symbolTable.getReturnFuncType() != SymbolTable.ReturnFuncType.VOID) {
                returnExp.analyze(symbolTable);
            }
            if (!semicn.getIsCorrect()) {
                symbolTable.addError(semicn.getLineCnt() + " i");
            }
        } else if (stmtType == StmtType.LVALGETINT) {
            getintLVal.analyze(symbolTable);
            String type = symbolTable.getType(getintLVal.getIdentifier().getContent());
            if (type != null) {
                if (type.equals("ConstInt") || type.equals("ConstChar") ||
                        type.equals("ConstCharArray") || type.equals("ConstIntArray")) {
                    symbolTable.addError(getintLVal.getLineCnt() + " h");
                }
            }
            if (!inOrOutRparent.getIsCorrect()) {
                symbolTable.addError(inOrOutRparent.getLineCnt() + " j");
            }
            if (!semicn.getIsCorrect()) {
                symbolTable.addError(semicn.getLineCnt() + " i");
            }
        } else if (stmtType == StmtType.LVALGETCHAR) {
            getcharLVal.analyze(symbolTable);
            String type = symbolTable.getType(getcharLVal.getIdentifier().getContent());
            if (type != null) {
                if (type.equals("ConstInt") || type.equals("ConstChar") ||
                        type.equals("ConstCharArray") || type.equals("ConstIntArray")) {
                    symbolTable.addError(getcharLVal.getLineCnt() + " h");
                }
            }
            if (!inOrOutRparent.getIsCorrect()) {
                symbolTable.addError(inOrOutRparent.getLineCnt() + " j");
            }
            if (!semicn.getIsCorrect()) {
                symbolTable.addError(semicn.getLineCnt() + " i");
            }
        } else if (stmtType == StmtType.PRINTSTMT) {
            for (Exp printExp: printExps) {
                printExp.analyze(symbolTable);
            }
            String s1 = "%d";
            String s2 = "%c";
            int cnt1 = countSubstring(strcon.getContent(), s1) + countSubstring(strcon.getContent(), s2);
            int cnt2 = printExps.size();
            if (cnt1 != cnt2) {
                symbolTable.addError(printftk.getLineCnt() + " l");
            }
            if (!inOrOutRparent.getIsCorrect()) {
                symbolTable.addError(inOrOutRparent.getLineCnt() + " j");
            }
            if (!semicn.getIsCorrect()) {
                symbolTable.addError(semicn.getLineCnt() + " i");
            }
        }
    }

    public StmtType getStmtType() {
        return stmtType;
    }

    public static int countSubstring(String str, String subStr) {
        if (str == null || subStr == null || str.isEmpty() || subStr.isEmpty()) {
            return 0;
        }

        int count = 0;
        int index = 0; // 从索引0开始搜索

        // 使用循环和indexOf来寻找子串
        while ((index = str.indexOf(subStr, index)) != -1) {
            count++;
            index += subStr.length(); // 更新索引为当前找到位置之后，防止重复计数
        }

        return count;
    }
}