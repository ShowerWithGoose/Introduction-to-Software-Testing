package syntaxTree;

import token.TokenType;

public class RelExp {
    private final RelExp left;
    private final AddExp right;
    private final TokenType operator;

    public RelExp(RelExp left, AddExp right, TokenType operator) {
        this.left = left;
        this.right = right;
        this.operator = operator;
    }
}
