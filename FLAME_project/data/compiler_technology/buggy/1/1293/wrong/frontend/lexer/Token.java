package frontend.lexer;

import frontend.lexer.LexType;

public class Token{
    private LexType lexType;
    private String value;
    private int lineNum;
    public LexType getLexType() {
        return lexType;
    }
    public String getValue() {
        return value;
    }

    public int getLineNum() {
        return lineNum;
    }

    public Token(LexType lexType, String value, int lineNum) {
        this.lexType = lexType;
        this.value = value;
        this.lineNum = lineNum;
    }
}
