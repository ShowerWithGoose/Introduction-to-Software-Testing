package frontend;

public class Token {
    private LexType type;
    private int lineNum;
    private String content;

    public Token(LexType type, int lineNum, String content) {
        this.type = type;
        this.lineNum = lineNum;
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    public int getLineNum() {
        return lineNum;
    }

    public LexType getType() {
        return type;
    }
}
