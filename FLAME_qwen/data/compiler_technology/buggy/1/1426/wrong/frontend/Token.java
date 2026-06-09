package frontend;

public class Token {
    private String value;
    private TokenType type;
    private int line;
    public Token(String value, TokenType type, int line)
    {
        this.value = value;
        this.type = type;
        this.line = line;
    }

    public String getValue(){
        return value;
    }
    public int getLine(){
        return line;
    }
    public TokenType getType(){
        return type;
    }
    public void setValue(String value){
        this.value = value;
    }
    public void setLine(int line){
        this.line = line;
    }
    public void setType(TokenType type){
        this.type = type;
    }
    @Override
    public String toString() {
        return type.name() + " " + value + "\n"; // 返回类型名称和标记文本
    }
}
