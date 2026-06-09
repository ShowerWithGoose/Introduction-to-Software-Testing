package frontend;

public class Token {
    private TokenType type;
    private String value;
    private int lineNum;

    public Token() {
        this.lineNum = 0;
        this.value = "";
        this.type = null;
    }

    public Token(TokenType type, String value, int lineNum) {
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }

    public TokenType getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void addChar(char c) {
        this.value += c;
    }

    public void setType(TokenType type) {
        this.type = type;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return type.toString() + ' ' + value + '\n';
    }
}
