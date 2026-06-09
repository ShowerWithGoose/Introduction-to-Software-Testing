package frontend.lexer;

public class Token {
    private final String value;
    private final TokenType tokenType;
    private final int lineNum;
    public Token(String value, TokenType type, int lineNum) {
        this.value = value;
        this.tokenType = type;
        this.lineNum = lineNum;
    }
    @Override
    public String toString() {
        return String.format("%s %s\n", tokenType, value);
    }

    /**
     * 获取单词所在行号
     * @return int 行号
     */
    public int getLine() {
        return lineNum;
    }

    /**
     * 获取单词的类型
     * @return TokenType 类型
     */
    public TokenType getType() {
        return tokenType;
    }

    /**
     * 获取单词的名字（也就是词法分析时的原始字符串）
     * @return String 单词的名字
     */
    public String getName() {
        return value;
    }

}

