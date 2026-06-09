package check;

public class Token {
    private T_type type;//类别码
    private String value;//单词值
    public Token(T_type type, String value){
        this.type = type;
        this.value = value;
    }

}
