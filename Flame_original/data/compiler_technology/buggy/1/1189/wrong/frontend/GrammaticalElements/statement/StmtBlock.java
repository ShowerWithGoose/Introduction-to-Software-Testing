package frontend.GrammaticalElements.statement;

public class StmtBlock extends StmtEle{
    private Block block;

    public StmtBlock(Block block) {
        this.block = block;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(block.toString());
        return sb.toString();
    }
}
