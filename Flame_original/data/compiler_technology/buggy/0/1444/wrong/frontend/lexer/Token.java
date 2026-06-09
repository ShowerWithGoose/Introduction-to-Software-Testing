package frontend.lexer;

public class Token {
    private TokenType tokenType;
    private String tokenValue;
    private int lineNum;

    private int numValue;

    public Token(TokenType tokenType, String tokenValue, int lineNum, int numValue){
        this.tokenType = tokenType;
        this.tokenValue = tokenValue;
        this.lineNum = lineNum;
        this.numValue = numValue;
    }
    public String getTokenTypeName(){
        return tokenType.toString();
    }
    public int getNumValue(){return numValue;}
    public String getTokenValue(){return tokenValue;}
    public int getLineNum(){return lineNum;}

}
