package frontend;

public class Token {
    private final LexType type;
    private final String content; //not value
    private final int lineNum; //line number in source file

    public Token(LexType type, String content, int lineNum) {
        this.type = type;
        this.content = content;
        this.lineNum = lineNum;
    }

    public String getContent() {
        return content;
    }

    public LexType getType() {
        return type;
    }
}
