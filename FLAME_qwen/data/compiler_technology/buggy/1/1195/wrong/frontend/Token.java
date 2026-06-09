package frontend;
public class Token {
    //词法分析的最小分析单位
    String token;//单词值
    LexType lexType;//单词类型
    int line;
    public Token(String token,LexType lexType,int line){
        this.lexType = lexType;
        this.token = token;
        this.line = line;
    }

    public String getToken() {
        return token;
    }//获得读取的单词值

    public LexType getLexType() {
        return lexType;
    }//获得读取的单词类型

    public int getLine() {
        return line;
    }
}
