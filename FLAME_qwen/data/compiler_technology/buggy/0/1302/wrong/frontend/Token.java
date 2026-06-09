package frontend;

public class Token {
    private final LexType type;
    private final String value;
    private final int lineNum;

    public Token(LexType type, String value, int lineNum) {
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }

    public LexType getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public int getLineNum() {
        return lineNum;
    }

    @Override
    public String toString() {
        return lineNum + ": " + type + " " + value;
    }
}
