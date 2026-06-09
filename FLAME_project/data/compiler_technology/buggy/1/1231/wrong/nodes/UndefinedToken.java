package nodes;

public class UndefinedToken extends Token{

    public UndefinedToken(TokenType type, String value, int line, int content) {
        super(type, value, line, content);
    }

    @Override
    public String toString() {
        return String.valueOf(super.lineNum) + " a";
    }
}
