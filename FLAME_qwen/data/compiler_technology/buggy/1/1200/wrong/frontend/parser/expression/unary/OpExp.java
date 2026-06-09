package frontend.parser.expression.unary;

import frontend.parser.expression.UnaryExp;

public class OpExp implements UExp {
    private UnaryOp op;
    private UnaryExp unaryExp;

    public OpExp(UnaryOp op, UnaryExp unaryExp) {
        this.op = op;
        this.unaryExp = unaryExp;
    }

    @Override
    public int getLineno() {
        return unaryExp.getLineno();
    }

    @Override
    public String getOutPut() {
        return op.getOutPut() + unaryExp.getOutPut();
    }

    @Override
    public String getError() {
        return unaryExp.getError();
    }
}
