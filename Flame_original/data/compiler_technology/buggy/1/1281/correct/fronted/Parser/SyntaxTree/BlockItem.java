package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/13 10:56
 */
public class BlockItem implements SyntaxNode{
    private final String name = "<BlockItem>";
    private SyntaxNode BlockItemNode;  //Decl | Stmt

    public BlockItem(SyntaxNode blockItemNode) {
        BlockItemNode = blockItemNode;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.BlockItemNode.output());
        return sb.toString();
    }
}
