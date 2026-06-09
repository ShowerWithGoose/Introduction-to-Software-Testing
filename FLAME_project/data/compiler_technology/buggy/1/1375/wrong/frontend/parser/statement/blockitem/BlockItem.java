package frontend.parser.statement.blockitem;

import frontend.parser.SyntaxNode;

public class BlockItem implements SyntaxNode {
    public final String name ="<BlockItem>";
    public BlockItemEle blockItemEle;
    public BlockItem(BlockItemEle blockItemEle) {
        this.blockItemEle = blockItemEle;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.blockItemEle.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num(){
        return this.blockItemEle.my_line_num();
    }
}
