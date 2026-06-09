package syntaxTree;

import token.TokenType;

public class UnaryOpResult extends UnaryExp {
    private final UnaryExp unaryExp;
    private final TokenType operators;

    public UnaryOpResult(UnaryExp unaryExp, TokenType operators) {
        this.unaryExp = unaryExp;
        this.operators = operators;
    }
}
