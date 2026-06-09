package frontend.parser.ast.exp;

import frontend.lexer.Token;

public class UnaryOp {
    private String type = "<UnaryOp>";
    private Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }

    public String getOutput() {
        return token.getOutput() + type + "\n";
    }

}
