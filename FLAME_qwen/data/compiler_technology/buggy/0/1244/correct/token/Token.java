package token;

public class Token {
    private TokenType type;
    private String content;
    private int lineno;

    public Token(TokenType type, String content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }

    @Override
    public String toString() {
        return type.toString() + " " + content;
    }
}

