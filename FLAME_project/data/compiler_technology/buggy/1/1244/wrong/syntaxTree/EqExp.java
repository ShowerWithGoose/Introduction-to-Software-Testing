package syntaxTree;

import token.TokenType;

public class EqExp {
    private final EqExp left;
    private final RelExp right;
    private final TokenType operator;

    public EqExp(EqExp left, RelExp right, TokenType operator) {
        this.left = left;
        this.right = right;
        this.operator = operator;
    }
}
