package frontend.parser.expression.unaryexp;

/**
 * UnaryExpOp <UnaryExp>Op子节点类
 * <UnaryOp> <UnaryExp>
 */
public class UnaryExpOp implements UnaryExpEle {
    /**
     * 属性：
     * unary <UnaryOp>
     * unaryExp <UnaryExp>，右递归
     */
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExpOp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryOp.syntaxOutput());
        sb.append(this.unaryExp.syntaxOutput());
        return sb.toString();
    }
}
