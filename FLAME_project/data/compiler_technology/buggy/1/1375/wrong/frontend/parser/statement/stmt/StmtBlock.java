package frontend.parser.statement.stmt;

import frontend.parser.statement.Block;

public class StmtBlock implements StmtEle {
    public Block block;

    public StmtBlock(Block block) {
        this.block = block;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.block.syntaxOutput());
        return sb.toString();
    }

    @Override
    public int my_line_num() {
        return block.my_line_num();
    }
}
