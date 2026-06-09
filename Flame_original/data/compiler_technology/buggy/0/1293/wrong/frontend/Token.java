package frontend;

public class Token {
    private LexType lexType;
    private String value;
    public LexType getLexType() {
        return lexType;
    }
    public String getValue() {
        return value;
    }
    public Token(LexType lexType, String value) {
        this.lexType = lexType;
        this.value = value;
    }
}
