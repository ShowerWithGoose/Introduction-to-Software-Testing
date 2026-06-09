package frontend.expression.primaryexp;

import frontend.Token;
import frontend.expression.Exp;

public class PrimaryExpExp implements PrimaryExpEle {
    private final Token leftParent;
    private final Exp exp;
    private final Token rightParent;

    public PrimaryExpExp(Token leftParent, Exp exp, Token rightParent) {
        this.leftParent = leftParent;
        this.exp = exp;
        this.rightParent = rightParent;
    }

    @Override
    public String syntaxOutput() {
        return new StringBuilder()
                .append(leftParent.syntaxOutput())
                .append(exp.syntaxOutput())
                .append(rightParent.syntaxOutput())
                .toString();
    }
}
