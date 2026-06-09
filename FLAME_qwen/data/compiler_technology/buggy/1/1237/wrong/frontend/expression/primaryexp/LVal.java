package frontend.expression.primaryexp;

import frontend.Token;
import frontend.terminal.Ident;
import frontend.expression.Exp;

import java.util.List;

public class LVal implements PrimaryExpEle {
    private final String name = "<LVal>";
    private final Ident ident;
    private final List<Token> leftBrackets;
    private final List<Exp> exps;
    private final List<Token> rightBrackets;

    public LVal(Ident ident, List<Token> leftBrackets, List<Exp> exps, List<Token> rightBrackets) {
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.exps = exps;
        this.rightBrackets = rightBrackets;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder(ident.syntaxOutput());

        if (leftBrackets != null && exps != null && rightBrackets != null &&
                leftBrackets.size() == exps.size() && exps.size() == rightBrackets.size()) {
            for (int i = 0; i < leftBrackets.size(); i++) {
                sb.append(leftBrackets.get(i).syntaxOutput())
                        .append(exps.get(i).syntaxOutput())
                        .append(rightBrackets.get(i).syntaxOutput());
            }
        }
        sb.append("<LVal>\n");
        return sb.toString();
    }
}
