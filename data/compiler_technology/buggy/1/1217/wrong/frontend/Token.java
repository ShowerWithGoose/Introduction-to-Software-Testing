package frontend;

public class Token {
    public LexType type;
    public int lineNumber;
    public String word;
    public Token(LexType type, int lineNumber, String word) {
        this.type = type;
        this.lineNumber = lineNumber;
        this.word = word;
    };
}
