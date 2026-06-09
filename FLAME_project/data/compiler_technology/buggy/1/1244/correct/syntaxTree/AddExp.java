package syntaxTree;

import token.TokenType;

public class AddExp implements ConstExp, Exp {
    private final AddExp left;
    private final MulExp right;
    private final TokenType operator;

    public AddExp(AddExp left, MulExp right, TokenType operator) {
        this.left = left;
        this.right = right;
        this.operator = operator;
    }
}
