package frontend.Parser.Expression.UnaryExpElements;

import frontend.Parser.Expression.UnaryExp;
import frontend.Parser.Expression.UnaryOp;
import frontend.Parser.Expression.unaryExpEle;

public class UnaryOpExp implements unaryExpEle {
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryOpExp (UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryOp.printString());
        sb.append(unaryExp.printString());
        return sb.toString();
    }
}
