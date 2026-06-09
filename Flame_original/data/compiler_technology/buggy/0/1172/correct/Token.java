public class Token {
    private TokenType type; // 单词类型
    private String content; // 单词内容
    private int line; // 单词所在行号

    // 构造方法，初始化单词
    public Token(TokenType type, String content, int line) {
        this.type = type;
        this.content = content;
        this.line = line;
    }

    // 返回单词的字符串表示形式
    @Override
    public String toString() {
        return type + " " + content;
    }
}
