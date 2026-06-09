package frontend;

public class Token {
    private TokenType type;
    private int lineNumber;
    private String content;

    public Token(TokenType type, int lineNumber, String content) {
        this.type = type;
        this.lineNumber = lineNumber;
        this.content = content;
    }

    public TokenType getType() {
        return type;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public String getContent() {
        return content;
    }
}
