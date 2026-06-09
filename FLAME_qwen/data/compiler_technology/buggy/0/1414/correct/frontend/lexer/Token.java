package frontend.lexer;

public class Token {
    private TokenType type;
    private Object value;
    private int line;
    private boolean needSlash = false;

    public Token(TokenType type, Object value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }

    public Token(TokenType type, Object value, int line, boolean needSlash) {
        this.type = type;
        this.value = value;
        this.line = line;
        this.needSlash = needSlash;
    }

    public TokenType getType() {
        return this.type;
    }

    public String toString() {
        if (this.type == TokenType.CHRCON) {
            if (this.needSlash) {
                return this.type.toString() + " '\\" + this.value + "'";
            }
            return this.type.toString() + " '" + this.value + "'";
        }
        return this.type.toString() + " " + this.value.toString();
    }
}
