package frontend.SyntaxUnits.StmtUnits;

import frontend.SyntaxUnits.Block;


public class BlockStmt implements StmtUnit{
    private final Block block;

    public BlockStmt(Block block) {
        this.block = block;
    }

    @Override
    public String toPrint() {
        return block.toPrint();
    }
}
