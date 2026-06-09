package frontend.SyntaxUnits.Exps;

import frontend.LexType;
import frontend.SyntaxUnits.Exp;
import frontend.Token;

public class PrimaryExpExp implements PrimaryExpUnit {
    private final Exp exp;

    public PrimaryExpExp(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("LPARENT" + " (" +  "\n");
        stringBuilder.append(exp.toPrint());
        stringBuilder.append("RPARENT" + " )" +  "\n");
        return stringBuilder.toString();
    }
}
