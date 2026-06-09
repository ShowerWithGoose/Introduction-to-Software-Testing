package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/12 21:22
 */
public class PrimaryExp implements SyntaxNode{
    private final String name = "<PrimaryExp>";
    private SyntaxNode primaryExpNode;

    public PrimaryExp(SyntaxNode primaryExpNode) {
        this.primaryExpNode = primaryExpNode;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.primaryExpNode.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
