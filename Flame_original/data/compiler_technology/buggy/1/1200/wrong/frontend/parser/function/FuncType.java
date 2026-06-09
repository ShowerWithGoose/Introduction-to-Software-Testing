package frontend.parser.function;

import frontend.lexer.Token;

public class FuncType {
    private final String name = "<FuncType>";
    private Token token;

    public FuncType(Token token) {
        this.token = token;
    }

    public String getOutPut() {
        return token.getOutPut();
    }
}
