package frontend.TokenPart;

import frontend.Factor;

public class Token implements Factor {
    private TokenType type;
    private int lineNum;//行号
    private String value;//代表token的实际值
    public Token(TokenType type,String value,int lineNum){
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }
    public Token(TokenType type,String value){
        this.type = type;
        this.value = value;
        this.lineNum = 0;
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
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(type);
        sb.append(" ");
        sb.append(value);
        sb.append("\n");
        return sb.toString();
    }
}
