package frontend;

import error.ErrorType;

public class Token {
    private LexType lexType = null;
    private ErrorType errorType = null;
    private int lineNum;
    private String tokenValue;

    public Token(LexType type,int num,String value) {
        lexType = type;
        lineNum = num;
        tokenValue = value;
    }

    public Token(ErrorType type,int num,String value) {
        errorType = type;
        lineNum = num;
        tokenValue = value;
    }

    public LexType getLexType() {
        return lexType;
    }

    public ErrorType getErrorType() {
        return errorType;
    }

    public String getTokenValue() {
        return tokenValue;
    }

    public int getLineNum() {
        return lineNum;
    }
}

