package frontend.lexer;

// 词语类
public class Token {
    private TokenType tokenType;
    private int line;
//    private int column;
    private String content;

    public Token(TokenType tokenType, int line, String content) {
        this.tokenType = tokenType;
        this.line = line;
        this.content = content;
    }
    public TokenType getTokenType() {
        return tokenType;
    }
    public int getLine() {
        return line;
    }
    public String getContent() {
        return content;
    }

    public void setTokenType(TokenType tokenType) {
        this.tokenType = tokenType;
    }
    public void setLine(int line) {
        this.line = line;
    }
    public void setContent(String content) {
        this.content = content;
    }

}
