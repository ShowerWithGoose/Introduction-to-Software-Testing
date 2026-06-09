package frontend.Parser.Expression.PrimaryExpElements;

import frontend.Parser.Expression.primaryExpEle;
import frontend.Parser.Terminators.CharConst;

public class Character implements primaryExpEle {
    private CharConst charConst;

    public Character(CharConst charConst) {
        this.charConst = charConst;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.printString());
        sb.append("<" + "Character" + ">\n");
        return sb.toString();
    }
}
