package frontend.tokenLexer;

import error.ErrorType;

public class Token {
    private TokenType tokenType;
    private String token;
    private int line;
    private ErrorType errorType;

    public Token(String token, TokenType tokenType, int line, ErrorType errorType) {
        this.token = token;
        this.tokenType = tokenType;
        this.line = line;
        this.errorType = errorType;
    }

    public TokenType getTokenType() {
        return tokenType;
    }
    public String getToken(){
        return token;
    }
    public int getLine(){
        return line;
    }
    public ErrorType getErrorType(){
        return errorType;
    }
}
