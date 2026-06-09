package frontend.Parser.Stmt;

import frontend.Parser.Output;

public class BlockItem implements BlockItemInf {
    private final String name = "<BlockItem>";
    private BlockItemInf blockItemInf;

    public BlockItem(BlockItemInf blockItemInf) {
        this.blockItemInf = blockItemInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.blockItemInf.Parser_Output());
        return sb.toString();
    }
}
