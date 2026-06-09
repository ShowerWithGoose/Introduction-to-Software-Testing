package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/12 19:46
 */
public class ConstInitVal implements SyntaxNode{
    private final String name = "<ConstInitVal>";
    private SyntaxNode constInitValNode;

    public ConstInitVal(SyntaxNode constInitValNode) {
        this.constInitValNode = constInitValNode;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.constInitValNode.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
