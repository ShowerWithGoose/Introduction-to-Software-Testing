package frontend;

public class Token {
    private final String value;
    private final String type;
    private final int line;

    public Token(String value, String type, int line) {
        this.value = value;
        this.type = type;
        this.line = line;
    }

    @Override
    public String toString() {
        return type+" "+value;
    }
}