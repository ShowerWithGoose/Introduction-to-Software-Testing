package frontend;

public class Token {

    private final String content;
    private final TokenType type;

    public Token(TokenType type, String content) {
        this.type = type;
        this.content = content;
    }

    public String toString() {
        return type + " " + content;
    }

    public TokenType getType() {
        return type;
    }
}
