package frontend;

import frontend.Token;
import java.util.ArrayList;
import java.util.List;

public class TokenList {
    private final List<Token> tokens;  // 词法单元列表

    public TokenList() {
        this.tokens = new ArrayList<>();
    }

    /**
     * 添加 Token 到列表中
     * @param token 要添加的 Token，不能为 null
     */
    public void addToken(Token token) {
        if (token == null) {
            throw new IllegalArgumentException("Token cannot be null");
        }
        tokens.add(token);
    }

    /**
     * 获取所有 Token
     * @return 词法单元列表
     */
    public List<Token> getTokens() {
        return new ArrayList<>(tokens);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token).append("\n");
        }
        return sb.toString().trim();
    }
}