package frontend;

public class Token {
    private LexType lexType;
    private String name;
    private int number;
    private int line;

    public Token(LexType lexType, String name, int line) {
        this.lexType = lexType;
        this.name = name;
        this.line = line;
    }

    public String getName() {
        return this.name;
    }

    public LexType getLexType() {
        return this.lexType;
    }
}
