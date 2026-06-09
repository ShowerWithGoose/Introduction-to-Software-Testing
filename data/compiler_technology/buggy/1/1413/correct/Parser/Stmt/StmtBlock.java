package Parser.Stmt;

import Parser.Block;

public class StmtBlock implements StmtEle {
    private Block block;

    public StmtBlock(Block block) {
        this.block = block;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.block.print_tree());
        return sb.toString();
    }
}
