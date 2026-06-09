package parser_part;

import lexer_part.Token;
import parser_part.expression.primaryExpression.NumberComponent;

public class FloatConst implements NumberComponent {
    private Token token;

    public FloatConst(Token token) {
        this.token = token;
    }

    @Override
    public int compute() {
        return Integer.parseInt(token.getContent());
    }
}
