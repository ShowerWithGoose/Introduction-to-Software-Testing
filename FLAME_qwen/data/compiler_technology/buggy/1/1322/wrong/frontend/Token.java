package frontend;

public class Token {
    private LexType lexType;
    private String value;
    private int line;

    public Token(LexType lexType, String value, int line) {
        this.lexType = lexType;
        this.value = value;
        this.line = line;
    }

    public void setLexType(LexType lexType) {
        this.lexType = lexType;
    }

    public LexType getLexType() {
        return lexType;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }

    public void setLine(int line) {
        this.line = line;
    }

    public int getLine() {
        return line;
    }

    @Override
    public String toString() {
        return lexType.toString() + " " + value + "\n";
    }
}

