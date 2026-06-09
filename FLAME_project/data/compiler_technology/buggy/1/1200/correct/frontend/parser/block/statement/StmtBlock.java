package frontend.parser.block.statement;

import frontend.parser.block.Block;

public class StmtBlock implements Statement {
    private Block block;

    public StmtBlock(Block block) {
        this.block = block;
    }

    @Override
    public String getOutPut() {
        return block.getOutPut();
    }

    @Override
    public String getError() {
        return block.getError();
    }
}
