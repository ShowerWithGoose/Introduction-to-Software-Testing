package token;

public class Token {
    private int line;
    private String content;
    private TokenCode tokenCode;

    public Token(int line, String content, TokenCode tokenCode) {
        this.line = line;
        this.content = content;
        this.tokenCode = tokenCode;
    }

    public int getLine() {
        return line;
    }

    public String getContent() {
        return content;
    }

    public TokenCode getTokenCode() {
        return tokenCode;
    }

    @Override
    public String toString() {
        return tokenCode.toString() + " " + content;
    }
}
