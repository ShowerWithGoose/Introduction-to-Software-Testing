package frontend.Parser.Expression.PrimaryExpElements;

import frontend.Parser.Expression.primaryExpEle;
import frontend.Parser.Terminators.IntConst;

public class Number implements primaryExpEle {
    private IntConst intConst;

    public Number(IntConst intConst) {
        this.intConst = intConst;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(intConst.printString());
        sb.append("<" + "Number" + ">\n");
        return sb.toString();
    }
}
