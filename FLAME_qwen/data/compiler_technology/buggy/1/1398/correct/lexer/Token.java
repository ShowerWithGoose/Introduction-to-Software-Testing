package lexer;

public class Token {

    private TokenType type;
    private String value;
    private int lineNum;
    public Token(TokenType type, String value, int lineNum) {
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }

    public TokenType getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public int getLineNum() {
        return lineNum;
    }
    public void print() {
        System.out.println(type.toString() + ' ' + value);
    }
}
