package frontend.parser.block.statement;

import frontend.lexer.Token;
import frontend.parser.block.Cond;
import frontend.parser.block.Stmt;

public class StmtIf implements Statement {
    private Token ifTk;
    private Token lParent;
    private Cond cond;
    private Token rParent;
    private Stmt ifStmt;
    private Token elseTk = null;
    private Stmt elseStmt = null;
    private String errorLog = "";

    public StmtIf(Token ifTk, Token lParent, Cond cond, Token rParent,
                  Stmt ifStmt, Token elseTk, Stmt elseStmt) {
        this.ifTk = ifTk;
        this.lParent = lParent;
        this.cond = cond;
        this.rParent = rParent;
        this.ifStmt = ifStmt;
        this.elseTk = elseTk;
        this.elseStmt = elseStmt;
        if (rParent == null) {
            errorLog = cond.getLineno() + " j\n";
        }
    }

    public StmtIf(Token ifTk, Token lParent, Cond cond, Token rParent,
                  Stmt ifStmt) {
        this.ifTk = ifTk;
        this.lParent = lParent;
        this.cond = cond;
        this.rParent = rParent;
        this.ifStmt = ifStmt;
        if (rParent == null) {
            errorLog = cond.getLineno() + " j\n";
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(ifTk.getOutPut());
        sb.append(lParent.getOutPut());
        sb.append(cond.getOutPut());
        if (rParent != null) {
            sb.append(rParent.getOutPut());
        }
        sb.append(ifStmt.getOutPut());
        if (elseTk != null) {
            sb.append(elseTk.getOutPut());
            sb.append(elseStmt.getOutPut());
        }
        return sb.toString();
    }

    @Override
    public String getError() {
        StringBuilder sb = new StringBuilder();
        sb.append(cond.getError());
        sb.append(errorLog);
        sb.append(ifStmt.getError());
        if (elseTk != null) {
            sb.append(elseStmt.getError());
        }
        return sb.toString();
    }
}
