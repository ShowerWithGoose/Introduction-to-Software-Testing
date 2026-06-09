package frontend.Parser.terminal;

import frontend.Lexer.Token;

public class CharConst {
    private Token token;
    public CharConst(Token token) {
        this.token = token;
    }
    public Token getToken() {
        return this.token;
    }
}
