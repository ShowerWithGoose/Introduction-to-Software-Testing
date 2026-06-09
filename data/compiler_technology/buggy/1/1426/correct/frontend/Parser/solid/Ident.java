package frontend.Parser.solid;

import frontend.Token;
import frontend.TokenType;
import frontend.Parser.Output;

public class Ident implements Output {
    private Token token;

    public Ident(Token token) {
        this.token = token;
    }
    public Ident(String str, int line) {
        this.token = new Token(str, TokenType.IDENFR, line);
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.token.toString());
        return sb.toString();
    }

}
