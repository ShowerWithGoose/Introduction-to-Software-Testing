package lexical;

public class Token {
    public TokenType getType() {
        return type;
    }

    public String getRawString() {
        return rawString;
    }

    public int getLine() {
        return line;
    }

    private TokenType type;
    private String rawString;
    private int line;
    private boolean isKeyword = false;
    private boolean isInputOutput = false;
    private boolean isNumber = false;
    private boolean isChar = false;
    private boolean isString = false;
    private int valueInt = 0;
    private char valueChar = 0;
    private String valueString = null;

    public Token(TokenType type, String rawString, int line) {
        this.type = type;
        this.rawString = rawString;
        this.line = line;
    }
}
