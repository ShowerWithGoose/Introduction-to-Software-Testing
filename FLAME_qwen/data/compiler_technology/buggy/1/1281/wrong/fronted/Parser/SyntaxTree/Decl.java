package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/11 17:40
 */
public class Decl implements SyntaxNode{
    private final String name = "<Decl>";
    private SyntaxNode declNode;

    public Decl(SyntaxNode declNode) {
        this.declNode = declNode;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.declNode.output());
        return sb.toString();
    }
}
