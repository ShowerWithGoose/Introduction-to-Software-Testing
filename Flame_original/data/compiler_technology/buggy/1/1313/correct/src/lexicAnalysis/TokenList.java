package src.lexicAnalysis;

import java.util.ArrayList;
import java.util.List;

/**
 * 词法分析生成的单词列表
 */
public class TokenList {
    private List<Token> tokens;

    public TokenList() {
        this.tokens = new ArrayList<>();
    }

    public void add(Token token) {
        this.tokens.add(token);
    }

    public List<Token> getTokens() { // 支持返回单词序列，实现更多功能
        return this.tokens;
    }

    @Override
    public String toString() { // 输出为指定格式
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token.getTokenType()).append(" ").append(token.getContent()).append("\n");
        }
        return sb.toString();
    }
}
