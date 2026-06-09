package frontend.expression.primaryexp;

import frontend.expression.unaryexp.UnaryExpEle;

public class PrimaryExp implements UnaryExpEle {
    private final String name = "<PrimaryExp>";
    private final PrimaryExpEle primaryExpEle;

    public PrimaryExp(PrimaryExpEle primaryExpEle) {
        this.primaryExpEle = primaryExpEle;
    }

    @Override
    public String syntaxOutput() {
        return new StringBuilder()
                .append(primaryExpEle.syntaxOutput())
                .append(name)
                .append("\n")
                .toString();
    }
}
