package parser_part.expression.binaryExpression;

import lexer_part.Token;
import parser_part.expression.unaryExpression.UnaryExp;

import java.util.ArrayList;

public class MulExp extends BinaryExp<UnaryExp> {

    public MulExp(UnaryExp first, ArrayList<Token> ops, ArrayList<UnaryExp> expressions, String name) {
        super(first, ops, expressions, name);
    }

    public int getArray() {
        return getFirst().getArray();
    }
}
