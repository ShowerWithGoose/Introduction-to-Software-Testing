package frontend.Tree;

public class BlockItem {
    private Decl decl;

    private Stmt stmt;
    private int line;

    public BlockItem(Decl decl) {
        this.decl = decl;
    }

    public BlockItem(Stmt stmt, int line) {
        this.stmt = stmt;
        this.line = line;
    }

    public Stmt getStmt() {
        return stmt;
    }

    public int getLine() {
        return line;
    }
}
