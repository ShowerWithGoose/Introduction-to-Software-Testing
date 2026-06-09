package frontend.parser.expression.unaryExp;

public class UnaryExpOp implements UnaryExpUnit{
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExpOp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryOp.syntaxPrint());
        sb.append(unaryExp.syntaxPrint());
        return sb.toString();
    }
}
