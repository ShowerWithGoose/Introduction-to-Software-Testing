package frontend.SyntaxUnits.Exps;

public class UnaryExpExp implements UnaryExpUnit{
    private final UnaryOp unaryOp;
    private final UnaryExp unaryExp;

    public UnaryExpExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(unaryOp.toPrint());
        stringBuilder.append(unaryExp.toPrint());
        return stringBuilder.toString();
    }
}
