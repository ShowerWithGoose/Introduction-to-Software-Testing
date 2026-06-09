package fronted.lexer;

public class ErrorToken extends Token {
    public ErrorToken(TokenType type, String value, int line) {
        super(type, value, line);
    }
}
