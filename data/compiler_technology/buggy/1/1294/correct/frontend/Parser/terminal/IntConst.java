package frontend.Parser.terminal;

import frontend.Lexer.Token;

public class IntConst {
    private Token token;
    public IntConst(Token token) {
        this.token = token;
    }
    public Token getToken() {
        return this.token;
    }
}
