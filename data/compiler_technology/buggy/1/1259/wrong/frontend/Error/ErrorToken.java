package frontend.Error;

import frontend.Lexer.Token;
import frontend.Lexer.TokenType;

public class ErrorToken extends Token
{
    private ErrorType errorType;

    public ErrorToken(String content, int lineNo, ErrorType errorType) {
        type = TokenType.Error;
        this.content = content;
        this.lineNo = lineNo;
        this.errorType = errorType;
    }



    public ErrorType getErrorType() {
        return errorType;
    }
}
