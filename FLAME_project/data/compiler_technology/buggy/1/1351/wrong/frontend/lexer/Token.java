package frontend.lexer;

public class Token {
    private final TokenType tokenType;
    private final String content;
    private final int lineNo;
    private int charNo;
    public Token(TokenType tokenType, String content, int lineNo) {
        this.tokenType = tokenType;
        this.content = content;
        this.lineNo = lineNo;
    }

    public TokenType getType() {
        return tokenType;
    }

    public String getContent() {
        return content;
    }

    public int getLineNo() {
        return lineNo;
    }

    public int getCharNo() {
        return charNo;
    }

    @Override
    public String toString() {
        return tokenType + " " + content + "\n";
    }
}
