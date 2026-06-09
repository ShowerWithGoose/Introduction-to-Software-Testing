package frontend.lexer;

import java.util.Objects;

/**
 * @Description Token
 */

public class Token {
    private TokenType type;
    private String value;
    private int lineNum;

    public Token(TokenType type, String value, int lineNum) {
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }

    @Override
    public String toString() {
        // return "<" + type + ", " + value + ", l-" + lineNum + ">";
        return type + " " + value;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) {
            return true;
        }
        if (obj == null || obj.getClass() != this.getClass()) {
            return false;
        }
        Token token = (Token) obj;
        return type == token.type && value.equals(token.value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(type, value);
    }
}
