package frontend.Parser.Expression.PrimaryExpElements;

import frontend.Lexer.Token;
import frontend.Parser.Expression.Exp;
import frontend.Parser.Expression.primaryExpEle;

public class Exp_parent implements primaryExpEle {
    private Token lparentToken;
    private Exp exp;
    private Token rparentToken;

    public Exp_parent(Token lparentToken, Exp exp, Token rparentToken) {
        this.lparentToken = lparentToken;
        this.exp = exp;
        this.rparentToken = rparentToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lparentToken);
        sb.append(exp.printString());
        if (rparentToken != null) {
            sb.append(rparentToken);
        }
        return sb.toString();
    }
}
