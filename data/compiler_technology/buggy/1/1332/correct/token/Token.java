package token;

/**
 * ClassName: Token
 * Package: token
 * Description:
 *
 * @Author
 * @Create 2024/9/23 19:25
 * @Version 1.0
 */
public class Token {
    public String content;
    public TokenType type;
    public int lineNo;
    public int thisLineTokenNo; // the columnNo-th token
    public int thisLineCharNo;
    public int value; // maybe create a INTCONST class extends Token

    public Token(){

    }

    public Token(String content, TokenType type, int lineNo, int thisLineTokenNo) {
        this.content = content;
        this.type = type;
        this.lineNo = lineNo;
        this.thisLineTokenNo = thisLineTokenNo;
    }

    public Token(String content, TokenType type, int lineNo, int thisLineTokenNo, int value) {
        this.content = content;
        this.type = type;
        this.lineNo = lineNo;
        this.thisLineTokenNo = thisLineTokenNo;
        this.value = value;
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(this.type).append(" ").append(this.content).append("\n");
        return info;
    }
}
