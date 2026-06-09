package frontend;

public class Token {
    private TokenType type;
    private int lineNum;//行号
    private String value;//代表token的实际值
    public Token(TokenType type,String value,int lineNum){
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }
    public TokenType getType(){
        return type;
    }
    public int getLineNum(){
        return lineNum;
    }
    public String getValue(){
        return value;
    }
}
