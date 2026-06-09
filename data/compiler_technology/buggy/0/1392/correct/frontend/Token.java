package frontend;

public class Token {
    private TokenType tokenType;
    private int lineNum;
    private String content;
    public Token(TokenType tokenType, int lineNum, String content){
        this.tokenType = tokenType;
        this.lineNum = lineNum;
        this.content = content;
    }
    public String toString(){
        if (this.tokenType==TokenType.HELP){
            return this.lineNum+" "+this.content;
        } else { return this.tokenType+" "+this.content; }
    }
}
