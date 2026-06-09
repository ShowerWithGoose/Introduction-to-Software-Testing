package frontend.parser.statement.blockitem;

import frontend.parser.SyntaxNode;

/**
 * BlockItem 语句块项类
 * <BlockItem> -> <Decl> | <Stmt>
 */
public class BlockItem implements SyntaxNode {
    private final String name = "<BlockItem>";
    private BlockItemEle blockItemEle;

    public BlockItem(BlockItemEle blockItemEle) {
        this.blockItemEle = blockItemEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.blockItemEle.syntaxOutput());
        //sb.append(this.name + "\n");
        return sb.toString();
    }
}
