package frontend.parser.ast.block;

import frontend.lexer.Token;

public class StmtFor implements Statement {
    private Token forToken;
    private Token lParent;
    private ForStmt stmt1;
    private Token semi1;
    private Cond cond;
    private Token semi2;
    private ForStmt stmt3;
    private Token rParent;
    private Stmt stmt;
    private String error;

    public StmtFor(Token forToken, Token lParent, ForStmt stmt1, Token semi1, Cond cond, Token semi2, ForStmt stmt3, Token rParent, Stmt stmt) {
        this.forToken = forToken;
        this.lParent = lParent;
        this.stmt1 = stmt1;
        this.semi1 = semi1;
        this.cond = cond;
        this.semi2 = semi2;
        this.stmt3 = stmt3;
        this.rParent = rParent;
        this.stmt = stmt;
        this.error = "";
        if (rParent == null) {
            if (stmt3 != null) {
                this.error = stmt3.getLineno() + " j\n";
            } else {
                this.error = semi2.getLineno() + " j\n";
            }
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(forToken.getOutput());
        out.append(lParent.getOutput());
        if (stmt1 != null) {
            out.append(stmt1.getOutput());
        }
        out.append(semi1.getOutput());
        if (cond != null) {
            out.append(cond.getOutput());
        }
        out.append(semi2.getOutput());
        if (stmt3 != null) {
            out.append(stmt3.getOutput());
        }
        if (rParent != null) {
            out.append(rParent.getOutput());
        }
        out.append(stmt.getOutput());

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        if (stmt1 != null) {
            out.append(stmt1.getError());
        }
        if (cond != null) {
            out.append(cond.getError());
        }
        if (stmt3 != null) {
            out.append(stmt3.getError());
        }
        out.append(error);
        out.append(stmt.getError());

        return out.toString();
    }

}
