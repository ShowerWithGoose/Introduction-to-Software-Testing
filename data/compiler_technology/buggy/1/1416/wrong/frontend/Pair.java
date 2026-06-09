package frontend;

public class Pair {
    private final int line_num;
    private final LexType key;
    private final String value;

    public Pair(int line_num, LexType key, String value) {
        this.line_num = line_num;
        this.key = key;
        this.value = value;
    }

    public Pair(int line_num, String value) {
        this.line_num = line_num;
        this.key = null;
        this.value = value;
    }

    public LexType getKey() {
        return this.key;
    }

    public String getValue() {
        return this.value;
    }

    public int getLine_num() {
        return line_num;
    }
}
