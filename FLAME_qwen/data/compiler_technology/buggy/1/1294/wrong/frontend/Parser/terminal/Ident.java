package frontend.Parser.terminal;

import frontend.Lexer.Token;

public class Ident {
    private Token token;

    public Ident(Token token) {
        this.token = token;
    }

    public Token getToken() {
        return token;
    }
}
