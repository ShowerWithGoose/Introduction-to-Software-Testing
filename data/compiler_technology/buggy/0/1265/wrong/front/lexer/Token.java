package front.lexer;

/**
 * Token 类
 */
public class Token {
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
     * 重写 toString 方法
     *
     * @return 一行 token 的输出
     */
    @Override
    public String toString() {
        return line + " " + tokenType.toString() + " " + token;
    }
}
