public class Token {
    TokenType type;
    String value;
    int line;

    public Token(TokenType type, String value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }
}