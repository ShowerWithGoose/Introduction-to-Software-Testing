package frontend.tokens;

public class Blank extends Token{
    // constructor
    public Blank(String content, int line) {
        super(content, line);
        type = TokenType.BLANK;
    }
}
