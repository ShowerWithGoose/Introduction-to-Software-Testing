package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/12 19:25
 */
public class UnaryExp implements SyntaxNode{
    private final String name = "<UnaryExp>";
    private SyntaxNode unaryExpNode; // PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp

    public UnaryExp(SyntaxNode unaryExpNode) {
        this.unaryExpNode = unaryExpNode;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryExpNode.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
