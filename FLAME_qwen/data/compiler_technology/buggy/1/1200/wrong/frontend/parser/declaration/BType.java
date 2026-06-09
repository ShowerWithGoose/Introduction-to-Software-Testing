package frontend.parser.declaration;

import frontend.lexer.Token;

public class BType {
    private final String name = "<Btype>";
    private Token token;

    public BType(Token token) {
        this.token = token;
    }

    public String getOutPut() {
        return token.getOutPut();
    }
}
