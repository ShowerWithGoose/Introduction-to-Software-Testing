package frontend;

public class Pair {
    private final int lineNum;
    private final LexType key;
    private final String value;

    public Pair(int lineNum, LexType key, String value) {
        this.lineNum = lineNum;
        this.key = key;
        this.value = value;
    }

    public Pair(int lineNum, String value) {
        this.lineNum = lineNum;
        this.key = null;
        this.value = value;
    }

    public LexType getKey() {
        return this.key;
    }

    public String getValue() {
        return this.value;
    }
}
