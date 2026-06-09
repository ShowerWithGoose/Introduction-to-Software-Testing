package frontend;

public class Token {
    public TokenType type;
    public String content;
    public int lineNum;

    public Token(TokenType type, String content, int lineNum) {
        this.type = type;
        this.content = content;
        this.lineNum = lineNum;
    }

    public String getContent() {
        return content;
    }

    public int getLineNum() {
        return lineNum;
    }

    public TokenType getType() {
        return type;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }

    public void setType(TokenType type) {
        this.type = type;
    }

    public void concat(char c) {
        content += c;
    }

    @Override
    public String toString() {
        if (type == TokenType.EOF) {
            return "";
        }
        return type + " " + content;
    }
}
