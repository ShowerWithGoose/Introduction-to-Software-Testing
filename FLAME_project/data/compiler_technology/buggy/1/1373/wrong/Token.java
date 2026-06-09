public class Token {
    private TokenType type;
    private String value;
    private int line;

    public Token(TokenType type, String value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }

    public String getType() {
        return this.type.toString();
    }

    public String getValue() {
        return  this.value;
    }

    public int getLine() {
        return  this.line;
    }
}
