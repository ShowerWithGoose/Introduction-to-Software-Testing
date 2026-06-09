package frontend.parser.expression.unaryexp;

public class UnaryExpOp implements UnaryExpEle{
    public UnaryOp unaryOp;
    public UnaryExp unaryExp;

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
    public int my_line_num() {
        return this.unaryExp.my_line_num();
    }
}
