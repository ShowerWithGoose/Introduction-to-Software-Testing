package token;

public class Token {
    public TokenType type;
    public String content;
    public int lineNumber;

    public Token(TokenType type, String content, int lineNumber) {
        this.type = type;
        this.content = content;
        this.lineNumber = lineNumber;
    }

    public String toString() {
        return this.type + " " + this.content;
    }
}
