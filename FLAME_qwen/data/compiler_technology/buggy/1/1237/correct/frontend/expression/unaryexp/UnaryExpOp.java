package frontend.expression.unaryexp;

public class UnaryExpOp implements UnaryExpEle {
    private final UnaryOp unaryOp;
    private final UnaryExp unaryExp;


    public UnaryExpOp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String syntaxOutput() {
        return new StringBuilder()
                .append(unaryOp.syntaxOutput())
                .append(unaryExp.syntaxOutput())
                .toString();
    }
}
