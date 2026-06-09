package Token;

public class Token {
    private int line;
    private String content;
    private TokenCode tokenCode;

    public Token(int line, String content, TokenCode tokenCode) {
        this.line = line;
        this.content = content;
        this.tokenCode = tokenCode;
    }

    @Override
    public String toString() {
        return tokenCode.toString() + " " + content;
    }
}
