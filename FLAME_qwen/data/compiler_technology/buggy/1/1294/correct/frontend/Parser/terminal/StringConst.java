package frontend.Parser.terminal;

import frontend.Lexer.Token;

public class StringConst {
    private Token token;

    public StringConst(Token token) {
        this.token = token;
    }
    public Token getToken() {
        return token;
    }
}
