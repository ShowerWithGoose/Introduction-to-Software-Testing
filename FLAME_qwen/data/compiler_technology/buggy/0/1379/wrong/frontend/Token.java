package frontend;

import frontend.LexType;

public class Token {
    private String content;
    private LexType type;
    private int lineNum;

    public Token(String content, LexType type,int lineNum) {
        this.content = content;
        this.type = type;
        this.lineNum = lineNum;
    }

    public String getContent() {
        return content;
    }

    public LexType getType() {
        return type;
    }


}
