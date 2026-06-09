package frontend.SyntaxUnits.Exps;

import frontend.SyntaxUnits.Exp;
import frontend.Token;

public class LVal implements PrimaryExpUnit {
    private final Token ident;
    private final Exp exp;

    public LVal(Token ident, Exp exp)  {
        this.exp = exp;
        this.ident = ident;
    }

    public LVal(Token ident)  {
        this.exp = null;
        this.ident = ident;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(ident.toPrint());
        if (exp != null) {
            stringBuilder.append("LBRACK" + " [" + "\n");
            stringBuilder.append(exp.toPrint());
            stringBuilder.append("RBRACK" + " ]" + "\n");
        }
        stringBuilder.append("<LVal>\n");
        return stringBuilder.toString();
    }
}
