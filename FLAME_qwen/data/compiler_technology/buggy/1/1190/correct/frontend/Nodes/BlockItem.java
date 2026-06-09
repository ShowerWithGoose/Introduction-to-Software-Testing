package frontend.Nodes;

public class BlockItem implements Node {
    private int type;
    private Decl decl;
    private Stmt stmt;

    public BlockItem() {
        this.type = 0;
        this.decl = null;
        this.stmt = null;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void addDecl(Decl decl) {
        this.decl = decl;
    }

    public void addStmt(Stmt stmt) {
        this.stmt = stmt;
    }

    @Override
    public String error() {
        return switch (type) {
            case 1 -> decl.error();
            case 2 -> stmt.error();
            default -> "";
        };
    }

    @Override
    public String toString() {
        return switch (type) {
            case 1 -> decl.toString();
            case 2 -> stmt.toString();
            default -> "";
        };
    }
}
