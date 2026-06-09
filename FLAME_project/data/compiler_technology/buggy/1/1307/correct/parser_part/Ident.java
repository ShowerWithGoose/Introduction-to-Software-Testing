package parser_part;

import lexer_part.Token;

public class Ident implements Node {
    private Token token;

    public Ident(Token token) {
        this.token = token;
    }

    @Override
    public String toString() {
        return token.toString();
    }

    public int getLineIndex() {
        return token.getLineIndex();
    }

    public String getName() {
        return token.getContent();
    }
}
