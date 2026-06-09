public class Token {
    private TokenType type;
    private String value;

    public Token(TokenType type, String value) {
        this.type = type;
        this.value = value;
    }

    public String getType() {
        return this.type.toString();
    }

    public String getValue() {
        return  this.value;
    }
}
