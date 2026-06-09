package frontend;

public class Pair {
    private final LexType key;
    private final String value;

    public Pair(LexType key, String value) {
        this.key = key;
        this.value = value;
    }

    public LexType getKey() {
        return this.key;
    }

    public String getValue() {
        return this.value;
    }
}
