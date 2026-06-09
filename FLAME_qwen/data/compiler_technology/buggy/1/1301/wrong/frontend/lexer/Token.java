package frontend.lexer;

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

    public int getLineNum() {
        return lineNum;
    }

    public boolean equals(LexType type) {
        return this.type == type;
    }

    public boolean equals(Token token) {
        if (this.type != token.type) {
            return false;
        } else {
            if (this.type == LexType.IDENFR || this.type == LexType.INTCON || this.type == LexType.STRCON || this.type == LexType.CHRCON) {
                return this.content.equals(token.content);
            } else {
                return true;
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(type + " " + content + "\n");
        return sb.toString();
    }
}
