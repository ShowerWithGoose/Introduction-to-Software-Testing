package frontend.declaration;

import frontend.Token;
import frontend.TokenType;
import frontend.SyntaxNode;

/**
 * 基本类型 BType
 */
public class BType implements SyntaxNode {
    private final Token token;
    private final String name = "<BType>";

    public BType(Token token) {
        if (token == null) {
            throw new IllegalArgumentException("Token cannot be null");
        }
        if (token.getType() != TokenType.INTTK && token.getType() != TokenType.CHARTK) {
            throw new IllegalArgumentException("Token must be of type INTTK or CHARTK");
        }
        this.token = token;
    }

    @Override
    public String syntaxOutput() {
        return token.syntaxOutput();
    }

    @Override
    public String toString() {
        return token.getContent();
    }
}
