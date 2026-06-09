package Fronted.parser.syntax;

// BlockItem â†’ Decl | Stmt
public class BlockItem {

    private static final String name = "<BlockItem>";

    private Decl decl = null;

    private Stmt stmt = null;

    public BlockItem(Decl decl) {
        this.decl = decl;
    }

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        if (decl!= null) {
            out.append(decl);
        } else {
            out.append(stmt);
        }
        return out.toString();
    }

    public Decl getDecl() {
        return decl;
    }

    public void setDecl(Decl decl) {
        this.decl = decl;
    }

    public Stmt getStmt() {
        return stmt;
    }

    public void setStmt(Stmt stmt) {
        this.stmt = stmt;
    }
}
