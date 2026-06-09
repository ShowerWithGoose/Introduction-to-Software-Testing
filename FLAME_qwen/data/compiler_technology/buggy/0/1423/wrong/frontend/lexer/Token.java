package frontend.lexer;

/**
 * @author
 * 保存解析出的某个 Token 的信息
 * 用 ArrayList 来维护错误表
 */
public class Token {
    private TokenType type; // 单词类别
    private int lineNum; // 行号
    private String content; // 单词的字符/字符串形式

    public Token(TokenType type, int lineNum, String content) {
        this.type = type;
        this.lineNum = lineNum;
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    public int getLineNum() {
        return lineNum;
    }

    public TokenType getType() {
        return type;
    }

    public void setType(TokenType type) {
        this.type = type;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }
}
