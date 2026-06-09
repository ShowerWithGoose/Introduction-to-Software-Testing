package frontend.lexer;

public class Token {
    private TokenType type;
    private int rowNum;
    private int columnNum;
    private String name;

    public Token(TokenType type, String name, int line) {
        this.type = type;
        this.name = name;
        this.rowNum = line;
    }

    public Token(TokenType type, int line) {
        this.type = type;
        this.name = type.TokenName();
        this.rowNum = line;
    }

    @Override
    public String toString() {
        return this.type + " " + this.name;
    }

}
