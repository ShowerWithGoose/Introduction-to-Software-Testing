package parser.block;

public class BlockStmt implements Stmt{
    private final Block block;

    public BlockStmt(Block block) {
        this.block = block;
    }

    public String toString() {
        return this.block.toString() + "<Stmt>\n";
    }
}
