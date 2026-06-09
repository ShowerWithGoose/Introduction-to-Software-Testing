package frontend;

public class Token {
    private String value;
    private int line;
    private Tokentype type;

    public Token(String value, int line, Tokentype type) {
        this.value = value;
        this.type = type;
        this.line = line;
    }

    @Override
    public String toString() {
        return type.toString() + " " + value;
    }

    public int getline() {
        return line;
    }

    public Tokentype gettype() {
        return type;
    }

    public String getvalue() {
        return value;
    }
}