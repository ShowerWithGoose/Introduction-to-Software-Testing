package frontend;

import java.util.Objects;

public class Token {
    public final TokenType type;
    public final String value;
    public final int line;

    public Token(TokenType type, String value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Token token = (Token) o;
        return line == token.line && type == token.type && Objects.equals(value, token.value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(type, value, line);
    }

    @Override
    public String toString() {
        return type + " " + value;
    }
}
