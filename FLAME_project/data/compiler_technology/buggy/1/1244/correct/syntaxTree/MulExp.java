package syntaxTree;

import token.TokenType;

public class MulExp {
    private final MulExp left;
    private final UnaryExp right;
    private final TokenType operator;

    public MulExp(MulExp left,UnaryExp right, TokenType operator) {
        this.left = left;
        this.right = right;
        this.operator = operator;
    }
}
