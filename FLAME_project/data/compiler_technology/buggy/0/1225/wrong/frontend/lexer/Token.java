package frontend.lexer;

import utils.TokenType;

public class Token {
    private final TokenType type;
    private final String content;

    public Token(TokenType type, String content) {
        this.type = type;
        this.content = content;
    }

    public String getContent() {
        return this.content;
    }

    public int getLineNo() {
        return Integer.parseInt(this.content);
    }

    @Override
    public String toString() {
        return type.toString() + " " + content;
    }
}
