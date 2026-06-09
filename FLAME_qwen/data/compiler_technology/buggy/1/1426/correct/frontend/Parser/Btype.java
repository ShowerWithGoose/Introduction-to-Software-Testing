package frontend.Parser;

import frontend.Token;

public class Btype implements Output{
    private final String name = "<BType>";
    private Token token;

    public Btype(Token token) {
        this.token = token;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.toString());
        return sb.toString();
    }
}
