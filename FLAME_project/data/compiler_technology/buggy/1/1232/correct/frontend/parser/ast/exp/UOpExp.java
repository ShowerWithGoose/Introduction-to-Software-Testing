package frontend.parser.ast.exp;

public class UOpExp implements UExp {
    private UnaryOp op;
    private UnaryExp unaryExp;

    public UOpExp(UnaryOp op, UnaryExp unaryExp) {
        this.op = op;
        this.unaryExp = unaryExp;
    }

    public int getLineno() {
        return unaryExp.getLineno();
    }

    public String getOutput() {
        return op.getOutput() + unaryExp.getOutput();
    }

    public String getError() {
        return unaryExp.getError();
    }

}
