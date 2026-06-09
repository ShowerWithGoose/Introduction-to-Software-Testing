package parser_part;

import lexer_part.Token;
import parser_part.expression.primaryExpression.NumberComponent;

public class IntConst implements NumberComponent {
    private Token token;

    public IntConst(Token token) {
        this.token = token;
    }

    @Override
    public String toString() {
        return token.toString();
    }

    @Override
    public int compute() {
        return Integer.parseInt(token.getContent());
    }
}
