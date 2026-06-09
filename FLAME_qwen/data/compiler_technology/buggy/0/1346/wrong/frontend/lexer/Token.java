package frontend.lexer;

/**
 * @author
 * @Description:
 * @date 2024/9/29 16:48
 */
public class Token {
    private LexType type; // 类别码
    private int lineNumber; // 所在行号
    private String content; // 具体内容

    public Token(LexType type, int lineNumber, String content) {
        this.type = type;
        this.lineNumber = lineNumber;
        this.content = content;
    }

    public LexType getType() {
        return type;
    }

    public void setType(LexType type) {
        this.type = type;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public void setLineNumber(int lineNumber) {
        this.lineNumber = lineNumber;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public String toString() {
        return type.toString() + " " + content + "\n";
    }
}
