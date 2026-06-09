package lexer;

public class Token {
    private String content;
    private TokenType type;
    private boolean error;
    private int lineNum;
    private int colNum;

    public Token() {}
    public Token(String content, TokenType type, boolean error, int lineNum, int colNum) {
        this.content = content;
        this.type = type;
        this.error = error;
        this.lineNum = lineNum;
        this.colNum = colNum;
    }

    public void setInfo(String content, TokenType type, boolean error) {
        this.content = content;
        this.type = type;
        this.error = error;
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

    public boolean getError() {
        return error;
    }

    public int getLineNum() {
        return lineNum;
    }

    public int getColNum() {
        return colNum;
    }
}
