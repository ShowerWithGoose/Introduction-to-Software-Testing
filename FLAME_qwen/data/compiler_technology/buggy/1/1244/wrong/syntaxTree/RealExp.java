package syntaxTree;

import token.TokenType;

public class RealExp {
    private AddExp left;
    private RealExp right;
    private TokenType operator;

    public RealExp(AddExp left, RealExp right, TokenType operator) {
        this.left = left;
        this.right = right;
        this.operator = operator;
    }
}
