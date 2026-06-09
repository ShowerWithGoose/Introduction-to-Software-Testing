package frontend.Parser.Stmt;

public class StmtBlock implements StmtInf{
    private Block block;

    public StmtBlock(Block block) {
        this.block = block;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.block.Parser_Output());
        return sb.toString();
    }

}
