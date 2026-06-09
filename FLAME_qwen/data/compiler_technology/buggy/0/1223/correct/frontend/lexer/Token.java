package frontend.lexer;

public class Token {
    private TokenType tokenType;
    private int lineNum;
    private String content;

    public Token(TokenType tokenType, int lineNum, String content) {
        this.tokenType = tokenType;
        this.lineNum = lineNum;
        this.content = content;
    }

    public TokenType getTokenType() {
        return tokenType;
    }

    public void setTokenType(TokenType tokenType) {
        this.tokenType = tokenType;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
