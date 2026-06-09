package token;

public class Token {
    private Type type;
    private String value;
    private int line;

    public Token(Type type, String value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }

    public Type getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return type.name() + " " + value;
    }

    public int getLine() {
        return line;
    }
}