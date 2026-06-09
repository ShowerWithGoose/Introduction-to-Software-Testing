package frontend.lexer;

public class Token {
    private TokenType type;
    private int lineNum;
    private String value;

    public Token(TokenType type, int lineNum, String value) {
        this.type = type;
        this.lineNum = lineNum;
        this.value = value;
    }

    @Override
    public String toString() {
        return type.toString() + " " + value + "\n";
    }

    public TokenType getType() {
        return this.type;
    }

    public String getValue() {
        return this.value;
    }

    public int getLineNum() {
        return this.lineNum;
    }
}

