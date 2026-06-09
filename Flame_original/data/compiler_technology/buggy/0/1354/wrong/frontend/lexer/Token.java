package frontend.lexer;

public class Token {
    public final TokenType type;
    public final String name;
    public final int lineIndex;
    public Token(TokenType type, String name, int lineIndex) {
        this.type = type;
        this.name = name;
        this.lineIndex = lineIndex;
    }
    @Override
    public String toString() {
        return type + " " + name + "\n";
    }
}
