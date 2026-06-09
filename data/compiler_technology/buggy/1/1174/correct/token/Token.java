package token;

public class Token {
    private String content;
    private TokenType type;
    private int lineNum;
    private int colNum;

    public Token() {}
    public Token(String content, TokenType type, int lineNum, int colNum) {
        this.content = content;
        this.type = type;
        this.lineNum = lineNum;
        this.colNum = colNum;
    }

    public void setInfo(String content, TokenType type) {
        this.content = content;
        this.type = type;
    }

    public void setPosition(int lineNum, int colNum) {
        this.lineNum = lineNum;
        this.colNum = colNum;
    }

    public String getContent() {
        return content;
    }

    public TokenType getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }

    public int getColNum() {
        return colNum;
    }
}
