package frontend;

public class Token {
    private TokenType type;
    private String value;
    private int lineNumber;

    public Token(TokenType type, String value, int lineNumber) {
        this.type = type;
        this.value = value;
        this.lineNumber = lineNumber;
    }

    public  String toString() {
        return String.format("%s %s", type, value);
    }
}
