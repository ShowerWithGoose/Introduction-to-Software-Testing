package common;

/**
 * The type Token.
 *
 * @author
 * @Descriptionï¼š
 * @date
 */
public class Token {
    private String str;
    private TokenType type;
    private int lineNum;

    /**
     * Instantiates a new Token.
     *
     * @param str     the str
     * @param type    the type
     * @param lineNum the line num
     */
    public Token(String str, TokenType type, int lineNum) {
        this.str = str;
        this.type = type;
        this.lineNum = lineNum;
    }

    /**
     * Gets line num.
     *
     * @return the line num
     */
    public int getLineNum() {
        return lineNum;
    }

    /**
     * Gets str.
     *
     * @return the str
     */
    public String getStr() {
        return str;
    }

    public TokenType getType() {
        return type;
    }
}
