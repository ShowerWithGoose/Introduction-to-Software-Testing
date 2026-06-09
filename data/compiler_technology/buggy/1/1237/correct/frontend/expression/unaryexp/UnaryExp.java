package frontend.expression.unaryexp;

import frontend.SyntaxNode;
import frontend.expression.unaryexp.UnaryExpEle;

public class UnaryExp implements SyntaxNode {
    private final UnaryExpEle unaryExpEle;
    private final String name = "<UnaryExp>";

    public UnaryExp(UnaryExpEle unaryExpEle) {
        this.unaryExpEle = unaryExpEle;
    }

    @Override
    public String syntaxOutput() {
        return new StringBuilder()
                .append(unaryExpEle.syntaxOutput())
                .append("<UnaryExp>\n")
                .toString();
    }
}
