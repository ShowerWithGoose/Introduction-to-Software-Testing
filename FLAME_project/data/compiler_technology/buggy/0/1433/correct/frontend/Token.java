package frontend;

public class Token {
    private TokenType type;
    private String value;
    private int lineno;

    public Token(TokenType type, String value, int lineNum) {
        this.type = type;
        this.value = value;
        this.lineno = lineNum;
    }

    public TokenType getType() {
        return type;
    }

    public int getLineno() {
        return lineno;
    }

    @Override
    public String toString() {
        return type.toString() + ' ' + value;
    }
}

