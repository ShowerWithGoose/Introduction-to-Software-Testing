package frontend.Parser.Stmt.Type;

import frontend.Parser.Del.Type.Decl;

public class BlockItem {
    // BlockItem â†’ Decl | Stmt
    private final Decl decl;
    private final Stmt stmt;

    public BlockItem(Decl decl) {
        this.decl = decl;
        this.stmt = null;
    }

    public BlockItem(Stmt stmt) {
        this.decl = null;
        this.stmt = stmt;
    }

    @Override
    public String toString() {
        return decl == null ? stmt.toString() : decl.toString();
    }
}
