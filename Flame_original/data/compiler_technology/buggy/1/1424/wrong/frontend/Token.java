package frontend;

public class Token {
    private TokenType type;
    private String val;
    private int line;
    public Token(TokenType type, String val, int line) {
        this.type = type;
        this.val = val;
        this.line = line;
    }

    public int getLine() {
        return line;
    }

    public TokenType getType() {
        return type;
    }

    public String getVal() {
        return val;
    }
}
