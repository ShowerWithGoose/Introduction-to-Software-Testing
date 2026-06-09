package parser.block;

public class IfStmt implements Stmt {
    private final Cond cond;
    private final Stmt ifStmt;
    private final Stmt elseStmt;

    public IfStmt(Cond cond, Stmt ifStmt, Stmt elseStmt) {
        this.cond = cond;
        this.ifStmt = ifStmt;
        this.elseStmt = elseStmt;
    }

    public String toString() {
        StringBuilder str = new StringBuilder("IFTK if\nLPARENT (\n");
        str.append(this.cond.toString());
        str.append("RPARENT )\n");
        str.append(this.ifStmt.toString());
        if (this.elseStmt != null) {
            str.append("ELSETK else\n" + this.elseStmt.toString());
        }
        str.append("<Stmt>\n");
        return str.toString();
    }
}
