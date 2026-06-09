package frontend;

/**
 * @Author:
 * @Date: 2024/9/29 21:15
 */
public class Token {
    private LexType lexType;
    private String value;

    public Token(LexType lexType,String value){
        this.lexType=lexType;
        this.value=value;
    }
    public LexType getType() {
        return lexType;
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return lexType + " " + value;
    }
}
