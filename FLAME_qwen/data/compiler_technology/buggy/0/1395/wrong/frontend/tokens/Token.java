package frontend.tokens;

public class Token {
    private final String content;
    private final int line;
    protected TokenType type;
    public Token(String content, int line) {
        this.content = content;
        this.line = line;
    }

    public String getContent() {
        return content;
    }

    public int getLine() {
        return line;
    }

    public TokenType getType() {
        return type;
    }

    @Override
    public String toString() {
        return type + " " + content;
    }


}
