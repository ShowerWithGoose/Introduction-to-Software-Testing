package frontend.parser.ast.block;

public class StmtBlock implements Statement {
    private Block block;

    public StmtBlock(Block block) {
        this.block = block;
    }

    public String getOutput() {
        return block.getOutput();
    }

    public String getError() {
        return block.getError();
    }
}
