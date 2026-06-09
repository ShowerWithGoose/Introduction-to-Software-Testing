package frontend.parser.block.statement;

import frontend.lexer.Token;
import frontend.parser.block.Cond;
import frontend.parser.block.ForStmt;
import frontend.parser.block.Stmt;

public class StmtFor implements Statement {
    private Token forTk;
    private Token lParent;
    private ForStmt stmt1;
    private Token semi1;
    private Cond cond;
    private Token semi2;
    private ForStmt stmt2;
    private Token rParent;
    private Stmt stmt;
    private String errorLog = "";

    public StmtFor(Token forTk, Token lParent, ForStmt stmt1,
                   Token semi1, Cond cond, Token semi2,
                   ForStmt stmt2, Token rParent, Stmt stmt) {
        this.forTk = forTk;
        this.lParent = lParent;
        this.stmt1 = stmt1;
        this.semi1 = semi1;
        this.cond = cond;
        this.semi2 = semi2;
        this.stmt2 = stmt2;
        this.rParent = rParent;
        this.stmt = stmt;
        if (rParent == null) {
            if (stmt2 != null) {
                errorLog = stmt2.getLineno() + " j\n";
            } else {
                errorLog = semi2.getLineno() + " j\n";
            }
        }

    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(forTk.getOutPut());
        sb.append(lParent.getOutPut());
        if (stmt1 != null) {
            sb.append(stmt1.getOutPut());
        }
        sb.append(semi1.getOutPut());
        if (cond != null) {
            sb.append(cond.getOutPut());
        }
        sb.append(semi2.getOutPut());
        if (stmt2 != null) {
            sb.append(stmt2.getOutPut());
        }
        if (rParent != null) {
            sb.append(rParent.getOutPut());
        }
        sb.append(stmt.getOutPut());
        return sb.toString();
    }

    @Override
    public String getError() {
        StringBuilder sb = new StringBuilder();
        if (stmt1 != null) {
            sb.append(stmt1.getError());
        }
        if (cond != null) {
            sb.append(cond.getError());
        }
        if (stmt2 != null) {
            sb.append(stmt2.getError());
        }
        sb.append(errorLog);
        sb.append(stmt.getError());
        return sb.toString();
    }
}
