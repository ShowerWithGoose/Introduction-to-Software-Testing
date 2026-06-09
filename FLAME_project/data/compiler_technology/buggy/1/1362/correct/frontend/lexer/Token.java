package frontend.lexer;

import frontend.lexer.TokenType;

public class Token {
    private TokenType type;
    private int lineNum;
    private String content;

    public Token(TokenType type, int lineNum, String content) {
        this.type = type;
        this.lineNum = lineNum;
        this.content = content;
    }

    public String getContent() {
        return this.content;
    }

    public int getLineNum() {
        return this.lineNum;
    }

    public TokenType getType() {
        return this.type;
    }

    public void setType(TokenType type) {
        this.type = type;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }
}
