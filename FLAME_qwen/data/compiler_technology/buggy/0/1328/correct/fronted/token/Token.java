package fronted.token;

public class Token {
    private TokenType type;
    private int lineNum;
    private String content;

    public Token(TokenType type, int lineNum, String content) {
        this.type = type;
        this.lineNum = lineNum;
        this.content = content;
    }

    /**
     * @return java.lang.String
     * @Description 正确单词输出格式
     * @date 2024/9/23 16:23
     * @version 1.0
     */
    @Override
    public String toString() {
        return type.toString() + " " + content + "\n";
    }
}
