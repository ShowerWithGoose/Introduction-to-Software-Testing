package frontend.Lexer;

public class Token {
    private TokenType type;
    //private int lineNum;
    private String stringContent;
    public Token(TokenType type, /*int lineNum,*/ String stringContent) {
        this.type = type;
        //this.lineNum = lineNum;
        this.stringContent = stringContent;
    }
    public TokenType getType() {
        return type;
    }
    /*public int getLineNum() {
        return lineNum;
    }*/
    public String getStringContent() {
        return stringContent;
    }
}
