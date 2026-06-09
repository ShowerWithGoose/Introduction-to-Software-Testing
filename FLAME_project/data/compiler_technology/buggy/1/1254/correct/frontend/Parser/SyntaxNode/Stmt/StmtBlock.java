package frontend.Parser.SyntaxNode.Stmt;

import frontend.Parser.SyntaxNode.Block;

public class StmtBlock extends Stmt {
    private Block block;

    public StmtBlock(Block block) {
        this.block = block;
    }

    @Override
    public String toString() {
        return block.toString() + name + "\n";
    }
}
