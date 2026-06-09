package frontend.lex;

public class Token {
    public final TokenType type;
    public final String content;
    public Token(final TokenType type, final String content) {
        this.type = type;
        this.content = content;
    }
}
