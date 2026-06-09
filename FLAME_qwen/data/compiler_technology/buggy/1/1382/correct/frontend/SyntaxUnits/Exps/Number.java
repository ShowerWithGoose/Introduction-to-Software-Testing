package frontend.SyntaxUnits.Exps;

import frontend.Token;


public class Number implements PrimaryExpUnit {
    private final Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(intConst.toPrint());
        stringBuilder.append("<Number>\n");
        return stringBuilder.toString();
    }
}
