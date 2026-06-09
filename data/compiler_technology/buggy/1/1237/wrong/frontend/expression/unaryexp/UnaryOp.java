package frontend.expression.unaryexp;

import frontend.Token;
import frontend.SyntaxNode;

public class UnaryOp implements SyntaxNode {
    private final Token token;
    private final String name = "<UnaryOp>";

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public String syntaxOutput() {
        return new StringBuilder()
                .append(token.syntaxOutput())
                .append("<UnaryOp>\n")
                .toString();
    }
}
