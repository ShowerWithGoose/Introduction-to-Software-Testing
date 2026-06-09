package frontend.Lexer;

/**
 * @author
 * @Description:
 * @date 2024/10/3 18:12
 */
public class Token {
    private String type;
    private String value;
    private int lineNum;

    public Token(String type, String value, int lineNum){
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }

    public void setType(String type){
        this.type = type;
    }

    public void setValue(String value){
        this.value = value;
    }

    public void setLineNum(int lineNum){
        this.lineNum = lineNum;
    }

    public String getType(){
        return type;
    }

    public String getValue(){
        return value;
    }

    public int getLineNum(){
        return lineNum;
    }
}
