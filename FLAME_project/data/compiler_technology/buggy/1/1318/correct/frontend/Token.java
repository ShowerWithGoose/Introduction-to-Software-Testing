package frontend;

import java.util.Locale;

public class Token {


    private final TokenType type;
    private final String text;
    private final int line;

    public Token(TokenType type, String text, int line) {
        this.type = type;
        this.text = text;
        this.line = line;
    }

    @Override
    public String toString() {
        return this.type.toString() + " " + this.text;
    }

    public TokenType getType() {
        return this.type;
    }

    public String getText() {
        return this.text;
    }

    public int getLine() {
        return this.line;
    }
}