package lexer;

public class Token {
    private final int position;
    private final TokenType type;
    private final String name;

    public Token(int position, TokenType type, String name) {
        this.position = position;
        this.type = type;
        this.name = name;
    }

    public String toString() {
        return this.type.getCode() + ' ' + this.name;
    }

    public int getPosition() {
        return this.position;
    }

    public String getName() {
        return this.name;
    }

    public TokenType getType() {
        return this.type;
    }
}
