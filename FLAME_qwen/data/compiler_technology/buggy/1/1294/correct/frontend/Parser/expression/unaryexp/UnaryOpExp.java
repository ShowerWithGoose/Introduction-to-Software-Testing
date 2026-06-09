package frontend.Parser.expression.unaryexp;

public class UnaryOpExp implements UnaryExpPort{
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;
    public UnaryOpExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryOp.grammarOutput());
        sb.append(unaryExp.grammarOutput());
        return sb.toString();
    }
}
