package frontend.Parser.Exp;

import frontend.Token;
import frontend.Parser.Output;

public class UnaryOp implements Output {
    private final String name = "<UnaryOp>";
    private Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.toString());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
