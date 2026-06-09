package frontend.lexer;

public class Token {
    private String value;
    private TokenType type;
    private int lineNum;

    public Token(String value, TokenType type, Integer lineNum) {
        this.value = value;
        this.type = type;
        this.lineNum = lineNum;
    }

    @Override
    public String toString(){
        return type.toString()+" "+value+"\n";
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public TokenType getType() {
        return type;
    }

    public void setType(TokenType type) {
        this.type = type;
    }

    public Integer getLineNum() {
        return lineNum;
    }

    public void setLineNum(Integer lineNum) {
        this.lineNum = lineNum;
    }
}
