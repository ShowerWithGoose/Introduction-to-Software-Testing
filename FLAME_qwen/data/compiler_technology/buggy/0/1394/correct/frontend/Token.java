package frontend;

public class Token {
    private TokenType type;
    private  String word;
    private long value;

    public Token(TokenType type,String word,long value) {
        this.type = type;
        this.word = word;
        this.value = value;
    }
    public TokenType getType() {
        return type;
    }
    public String getWord() {
        return word;
    }
    public long getValue() {
        return value;
    }
}
