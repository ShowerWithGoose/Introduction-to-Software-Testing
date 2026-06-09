package token;

public class Token {
    private final TokenType tokenType;
    private final String content;
    private final int line;

    public Token(TokenType tokenType, String content, int line) {
        this.tokenType = tokenType;
        this.content = content;
        this.line = line;
    }

    public TokenType getTokenType() {
        return tokenType;
    }

    public String getContent() {
        return content;
    }

    public int getLine() {
        return line;
    }

    public String toString() {
        return tokenType.toString() + " " + content + "\n";
    }
}
