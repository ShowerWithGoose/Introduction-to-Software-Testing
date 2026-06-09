package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/12 23:31
 */
public class UnaryExpNodeOfUnaryOp implements SyntaxNode{
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExpNodeOfUnaryOp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryOp.output());
        sb.append(this.unaryExp.output());
        return sb.toString();
    }
}
