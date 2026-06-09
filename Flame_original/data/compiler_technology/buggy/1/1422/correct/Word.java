public class Word {
    private final String token;
    private final LexType type;

    private long number = 0;
    private final int lineNum;

    public Word(String token, LexType type, long l, int lineNum) {
        this.token = token;
        this.type = type;
        this.number = l;
        this.lineNum = lineNum;
    }

    public String getToken() {
        return token;
    }

    public LexType getType() {
        return type;
    }

    public long getNumber() {
        return number;
    }

    public int getLineNum() {
        return lineNum;
    }
}
