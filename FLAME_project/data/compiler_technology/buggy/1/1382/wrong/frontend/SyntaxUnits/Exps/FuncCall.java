package frontend.SyntaxUnits.Exps;

import frontend.SyntaxUnits.FuncRParams;
import frontend.Token;

public class FuncCall implements UnaryExpUnit{
    private final Token ident;
    private final FuncRParams funcRParams;

    public FuncCall(Token ident, FuncRParams funcRParams) {
        this.ident = ident;
        this.funcRParams = funcRParams;
    }
    public FuncCall(Token ident) {
        this.ident = ident;
        this.funcRParams = null;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(ident.toPrint());
        stringBuilder.append("LPARENT" + " (" + "\n");
        if (funcRParams != null) {
            stringBuilder.append(funcRParams.toPrint());
        }
        stringBuilder.append("RPARENT" + " )" + "\n");
        return stringBuilder.toString();
    }
}
