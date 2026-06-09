package AST;

public class BlockItem {
    private Decl decl;
    private Stmt stmt;
    public BlockItem(Decl decl, Stmt stmt) {
        this.decl = decl;
        this.stmt = stmt;
    }
}
