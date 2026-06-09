package frontend.tokens;

public class IntCon extends Token {
    // regex
    public static final String REGEX = "[0-9]+";

    // constructor
    public IntCon(String content, int line) {
        super(content, line);
        type = TokenType.INTCON;
    }
}
