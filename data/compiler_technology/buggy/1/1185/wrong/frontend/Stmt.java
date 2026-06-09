package frontend;

public class Stmt {
    private TokenItaretor itaretor;
    private ParserFile file;
    private StmtContent stmtContent = null;

    public Stmt(TokenItaretor itaretor, ParserFile parserFile) {
        this.file = parserFile;
        this.itaretor = itaretor;
    }

    public void getStmt() {
        Token token = itaretor.getNext();
        if (token.getString().equals("{")) {
            itaretor.getPrevious(1);
            Block block = new Block(itaretor, file);
            block.getBlock();
            stmtContent = block;
        } else if (token.getString().equals("if")) {
            StmtIf ifStmt = new StmtIf(itaretor, file);
            ifStmt.getIfStmt(token);
            stmtContent = ifStmt;
        } else if (token.getString().equals("for")) {
            StmtFor stmtFor = new StmtFor(itaretor, file);
            stmtFor.getStmtFor(token);
            stmtContent = stmtFor;
        } else if (token.getString().equals("break")) {
            StmtBreak stmtBreak = new StmtBreak(itaretor, file);
            stmtBreak.getStmtBreak(token);
            stmtContent = stmtBreak;
        } else if (token.getString().equals("return")) {
            StmtReturn stmtReturn = new StmtReturn(itaretor, file);
            stmtReturn.getStmtReturn(token);
            stmtContent = stmtReturn;
        } else if (token.getString().equals("continue")) {
            StmtContinue stmtContinue = new StmtContinue(itaretor, file);
            stmtContinue.getStmtContinue(token);
            stmtContent = stmtContinue;
        } else if (token.getString().equals("printf")) {
            StmtPrintf stmtPrintf = new StmtPrintf(itaretor, file);
            stmtPrintf.getStmtPrintf(token);
            stmtContent = stmtPrintf;
        } else if (token.getString().equals(";")) {
            StmtExp stmtExp = new StmtExp(itaretor, file);
            stmtExp.getStmtExp(token);
            stmtContent = stmtExp;
        } else if (token.getType().equals("IDENFR")) {
            getIdentr(token);
        } else {
            StmtExp stmtExp = new StmtExp(itaretor, file);
            stmtExp.getStmtExp(token);
            stmtContent = stmtExp;
        }
        file.addToken(new Token("<Stmt>"));
    }

    public void getIdentr(Token token) {
        Token token1 = itaretor.getNext();
        if (!token1.getString().equals("(")) { //不是函数调用
            itaretor.getPrevious(1);
            if (!ifLVal()) {
                LVal lVal = new LVal(itaretor, file);
                lVal.getLVal(token);
                Token next = itaretor.getNext(); //=
                Token last = itaretor.getNext();
                if (next.getString().equals("=")) {
                    if (last.getString().equals("getint") || last.getString().equals("getchar")) {
                        StmtGet stmtGet = new StmtGet(itaretor, file);
                        itaretor.getPrevious(2);
                        stmtGet.getStmtGet(lVal);
                        stmtContent = stmtGet;
                    } else {
                        StmtAssign stmtExp = new StmtAssign(itaretor, file);
                        itaretor.getPrevious(2);
                        stmtExp.getStmtAssign(lVal);
                        stmtContent = stmtExp;
                    }
                }
            } else {
                StmtExp stmtExp = new StmtExp(itaretor, file);
                stmtExp.getStmtExp(token);
                stmtContent = stmtExp;

            }
        } else {
            itaretor.getPrevious(1);
            StmtExp stmtExp = new StmtExp(itaretor, file);
            stmtExp.getStmtExp(token);
            stmtContent = stmtExp;
        }
    }

    public boolean ifLVal() {
        int cnt = 0;
        boolean ifExp = false;
        Token next = itaretor.getNext();
        cnt = 1;
        if (next.getString().equals("[")) {
            Token token = itaretor.getNext();
            while (!token.getString().equals("]")) {
                cnt++;
                if (token.getString().equals("=")) {
                    itaretor.getPrevious(cnt);
                    ifExp = false;
                    return ifExp;
                }
                if (token.getString().equals(";")) {
                    itaretor.getPrevious(cnt);
                    ifExp = true;
                    return ifExp;
                }
                token = itaretor.getNext();
            }
            while (token.getString().equals("]")) {
                cnt++;
                token = itaretor.getNext();
            }
            cnt++;
            if (token.getString().equals("=")) {
                ifExp = false;
            } else {
                ifExp = true;
            }
        } else {
            if (next.getString().equals("=")) {
                ifExp = false;
            } else {
                ifExp = true;
            }
        }
        itaretor.getPrevious(cnt);
        return ifExp;
    }
}
