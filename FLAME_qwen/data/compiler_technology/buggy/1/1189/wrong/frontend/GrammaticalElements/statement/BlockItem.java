package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.declaration.Decl;

public class BlockItem {
    private Decl decl;
    private Stmt stmt;

    public BlockItem(Decl decl) {
        this.decl = decl;
    }

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (decl != null) {
            sb.append(decl.toString());
        } else {
            sb.append(stmt.toString());
        }
        return sb.toString();
    }
}
