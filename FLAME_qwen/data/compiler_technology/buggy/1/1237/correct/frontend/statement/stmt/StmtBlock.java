package frontend.statement.stmt;

import frontend.statement.Block;

public class StmtBlock implements StmtEle {
    private Block block;

    public StmtBlock(Block block) {
        this.block = block;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.block.syntaxOutput());
        return sb.toString();
    }
}
