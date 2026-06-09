package frontend.lexer;

import java.math.BigInteger;

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

    public Boolean in(TokenType... t) {
        for (TokenType type : t) {
            if (this.type.equals(type)) {
                return true;
            }
        }
        return false;
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

    public String getName() {
        return (String) value;
    }

    public String getString() {
        return (String) value;
    }

    public BigInteger getIntValue() {
        return new BigInteger((String) value);
    }

    public Character getCharValue() {
        return (Character) value;
    }

    public int getLine() {
        return line;
    }
}
