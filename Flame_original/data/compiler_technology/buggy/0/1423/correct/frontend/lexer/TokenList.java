package frontend.lexer;

import java.util.ArrayList;

/**
 * @author
 * 单词表
 * 用 ArrayList 来维护单词表
 */
public class TokenList {
    private ArrayList<Token> tokens;

    public TokenList() {
        this.tokens = new ArrayList<>();
    }

    /**
     * 将匹配出的 token 加入到单词表中
     * @param token 要加入单词表的 token
     */
    public void addToken(Token token) {
        this.tokens.add(token);
    }

    /**
     * 格式化输出单词表信息（每个 token 的类别码和字符/字符串形式）
     * @return 单词表的格式化输出
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token.getType() + " " + token.getContent() + "\n");
        }
        return sb.toString();
    }
}
