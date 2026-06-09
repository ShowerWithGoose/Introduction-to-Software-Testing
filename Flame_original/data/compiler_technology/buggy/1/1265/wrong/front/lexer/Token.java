package front.lexer;

/**
 * Token 类
 */
public class Token {
    /**
     * 读取 token 时超出范围时返回的值
     */
    static public Token OUT_INDEX = new Token(null, null, 0);
    /**
     * token 种类
     */
    TokenType tokenType;
    /**
     * token 实际的字符串
     */
    String token;
    /**
     * token 所在的行号
     */
    int line;

    /**
     * token 构造方法
     *
     * @param tokenType token 种类
     * @param token     token 实际的字符串
     * @param line      token 所在的行号
     */
    public Token(TokenType tokenType, String token, int line) {
        this.tokenType = tokenType;
        this.token = token;
        this.line = line;
    }

    /**
     * 获取 token 类型
     *
     * @return token 类型
     */
    public TokenType getTokenType() {
        return tokenType;
    }

    /**
     * 获取 token 原字符串
     *
     * @return token 原字符串
     */
    public String getToken() {
        return token;
    }

    /**
     * 获取 token 行号
     *
     * @return token 行号
     */
    public int getLine() {
        return line;
    }

    /**
     * 重写 toString 方法
     *
     * @return 一行 token 的输出
     */
    @Override
    public String toString() {
        return tokenType.toString() + " " + token;
    }
}
