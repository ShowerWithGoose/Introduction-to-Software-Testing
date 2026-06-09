package frontend.Lexer;

public class Token {
    private TokenType tokenType;
    private int lineNo; //行号
    private String value; //token具体的内容

    public Token(TokenType tokenType, int lineNo, String value) {
        this.tokenType = tokenType;
        this.lineNo = lineNo;
        this.value = value;
    }

    public String getValue(){
        return value;
    }

    public int getLineNo(){
        return lineNo;
    }

    public TokenType getTokenType() {
        return tokenType;
    }
}
