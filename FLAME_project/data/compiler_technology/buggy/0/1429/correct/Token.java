/**
 * Classname Token
 * Description TODO
 * Date 2024/10/4 17:01
 * Created ZHW
 */
public class Token {
    public String source;
    public String word;
    public TokenType type;
    public int length;
    public int curPos = 0; //当前位置
    public int lineNum = 1; //行号

    public Token(String source) {
        this.source = source;
        this.length = source.length();
    }

    public void clearToken() {
        word = "";
        type = null;
    }
}
