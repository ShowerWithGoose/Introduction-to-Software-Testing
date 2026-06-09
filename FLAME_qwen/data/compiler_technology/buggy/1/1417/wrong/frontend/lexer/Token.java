package frontend.lexer;

import frontend.parser.Node;

public class Token extends Node {
    private TokenType type;
    private String value;
    private int lineNumber;

    public Token(TokenType type, String value, int lineNumber) {
        super(lineNumber, lineNumber, value, null);
        this.type = type;
        this.value = value;
        this.lineNumber = lineNumber;
    }

    public String getValue() {
        return this.value;
    }

    public int getLineNumber() {
        return this.lineNumber;
    }

    public TokenType getType() {
        return this.type;
    }

    public String toString() {
        return type.toString() + ' ' + value;
    }


}
