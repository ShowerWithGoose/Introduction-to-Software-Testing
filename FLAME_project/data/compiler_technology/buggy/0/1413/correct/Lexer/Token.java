package Lexer;

/**
 * @Description:
 * @date 2024/9/24
 */
public class Token {


    private String type;//单词的类型
    private String value;//单词的值 也就是字符串
    private int line;   // 行号
    //private int column;  // 列号

    public Token(String type,String value,int line)
    {
        this.type=type;
        this.value=value;
        this.line=line;
    }
    public String getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public int getLine() {
        return line;
    }

    @Override
    public String toString() {
        return "Token{" +
                "type=" + type +
                ", value='" + value + '\'' +
                ", line=" + line +
                '}';
    }

}