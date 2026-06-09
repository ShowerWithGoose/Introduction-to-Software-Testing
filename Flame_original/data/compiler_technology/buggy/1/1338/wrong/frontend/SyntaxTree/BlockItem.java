package frontend.SyntaxTree;

public class BlockItem {
    private Stmt stmt;
    private Decl decl;

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
    }

    public BlockItem(Decl decl) {
        this.decl = decl;
    }
}
