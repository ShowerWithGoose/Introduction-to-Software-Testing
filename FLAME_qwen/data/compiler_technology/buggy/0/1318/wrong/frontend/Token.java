package frontend;

import java.util.Locale;

public class Token {


    private final TokenType type;
    private final String text;

    public Token(TokenType type, String text) {
        this.type = type;
        this.text = text;
    }

    @Override
    public String toString() {
        return this.type.toString() + " " + this.text;
    }
}