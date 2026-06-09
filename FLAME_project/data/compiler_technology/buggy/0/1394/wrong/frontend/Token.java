package frontend;

public class Token {
    private TokenType type;
    private  String word;
    private int value;

    public Token(TokenType type,String word,int value) {
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
    public int getValue() {
        return value;
    }
}
