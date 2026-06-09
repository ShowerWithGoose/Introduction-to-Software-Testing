package frontend;

import frontend.LexType;

public class Token {
    private LexType lexType;
    private Long value;
    private String str;

    public Token(LexType lexType,  Long value, String str) {
        this.str = str;
        this.value = value;
        this.lexType = lexType;
    }

    public String toPrint() {
        return lexType + " " + str; // for lexer
    }
}
