package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/13 1:32
 */
public class InitVal implements SyntaxNode{
    private final String name = "<InitVal>";
    private SyntaxNode initValNode;

    public InitVal(SyntaxNode initValNode) {
        this.initValNode = initValNode;
    }
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.initValNode.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
