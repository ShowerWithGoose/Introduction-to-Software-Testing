package frontend.parser.expression.unary;

import frontend.lexer.Token;

public class UnaryOp {
    private final String name = "<UnaryOp>";
    private Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }

    public String getOutPut() {
        return token.getOutPut() + name + "\n";
    }
}
