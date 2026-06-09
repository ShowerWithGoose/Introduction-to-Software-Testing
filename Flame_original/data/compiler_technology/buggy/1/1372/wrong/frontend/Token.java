package frontend;

import frontend.type.LexType;

public class Token {
    private final LexType lexType;
    private final Integer lineNum;
    private final String tokenValue;

    public Token(LexType lexType, Integer lineNum, String tokenValue) {
        this.lexType = lexType;
        this.lineNum = lineNum;
        this.tokenValue = tokenValue;
    }

    public LexType getLexType() {
        return lexType;
    }

    public String getTokenValue() {
        return tokenValue;
    }

    public Integer getLineNum() {
        return lineNum;
    }
}
