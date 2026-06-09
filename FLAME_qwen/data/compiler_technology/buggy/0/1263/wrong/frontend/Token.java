package frontend;

public class Token {
    private String token;
    private int line;
    private Tokentype type;

    public Token(String token, int line, Tokentype type) {
        this.token = token;
        this.type = type;
        this.line = line;
    }

    @Override
    public String toString() {
        return type.toString() + " " + token;
    }
}