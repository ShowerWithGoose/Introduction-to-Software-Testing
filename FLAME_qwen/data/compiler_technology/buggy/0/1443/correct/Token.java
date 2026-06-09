public class Token {
    private String name;

    private LexType lexType;


    public Token(String name, LexType lexType) {
        this.name = name;
        this.lexType = lexType;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public LexType getLexType() {
        return lexType;
    }

    public void setLexType(LexType lexType) {
        this.lexType = lexType;
    }
}
