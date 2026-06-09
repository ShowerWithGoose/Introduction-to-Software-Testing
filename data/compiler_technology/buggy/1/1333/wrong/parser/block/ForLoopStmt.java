package parser.block;

public class ForLoopStmt implements Stmt {
    private ForStmt forStmt1;
    private Cond cond;
    private ForStmt forStmt2;
    private Stmt stmt;

    public ForLoopStmt() {
        this.forStmt1 = null;
        this.stmt = null;
        this.forStmt2 = null;
        this.cond = null;
    }

    public void setForStmt1(ForStmt forStmt) {
        this.forStmt1 = forStmt;
    }

    public void setForStmt2(ForStmt forStmt) {
        this.forStmt2 = forStmt;
    }

    public void setCond(Cond cond) {
        this.cond = cond;
    }

    public void setStmt(Stmt stmt) {
        this.stmt = stmt;
    }

    public String toString() {
        StringBuilder str = new StringBuilder("FORTK for\nLPARENT (\n");
        if (this.forStmt1 != null) {
            str.append(this.forStmt1.toString());
        }
        str.append("SEMICN ;\n");
        if (this.cond != null) {
            str.append(this.cond.toString());
        }
        str.append("SEMICN ;\n");
        if (this.forStmt2 != null) {
            str.append(this.forStmt2.toString());
        }
        str.append("RPARENT )\n");
        str.append(this.stmt.toString());
        str.append("<Stmt>\n");
        return str.toString();
    }
}
