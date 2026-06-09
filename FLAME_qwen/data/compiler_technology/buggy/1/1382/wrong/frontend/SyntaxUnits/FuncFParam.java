package frontend.SyntaxUnits;

import frontend.Token;

public class FuncFParam implements SyntaxUnit{
    private BType bType;
    private Token ident;
    private boolean isArray;

    public FuncFParam(BType bType, Token ident, boolean  isArray) {
        this.bType = bType;
        this.isArray = isArray;
        this.ident = ident;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(bType.toPrint());
        stringBuilder.append(ident.toPrint());
        if (isArray) {
            stringBuilder.append("LBRACK" + " [" +  "\n");
            stringBuilder.append("RBRACK" + " ]" +  "\n");
        }
        stringBuilder.append("<FuncFParam>\n");
        return stringBuilder.toString();
    }
}
