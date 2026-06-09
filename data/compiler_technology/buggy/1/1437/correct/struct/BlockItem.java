package struct;

/* BlockItem â†’ Decl | Stmt */
public class BlockItem {
    private Decl decl;
    private Stmt stmt;

    public BlockItem(Decl decl) {
        this.decl = decl;
    }

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
    }

    public Decl getDecl() {
        return decl;
    }

    public Stmt getStmt() {
        return stmt;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (decl != null) {
            sb.append(decl.toString());
        } else {
            sb.append(stmt.toString());
        }
        // sb.append("<BlockItem>\n");
        return sb.toString();
    }
}
