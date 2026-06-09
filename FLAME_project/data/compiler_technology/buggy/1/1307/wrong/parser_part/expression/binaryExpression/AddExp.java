package parser_part.expression.binaryExpression;

import lexer_part.Token;

import java.util.ArrayList;

public class AddExp extends BinaryExp<MulExp> {

    public AddExp(MulExp first, ArrayList<Token> ops, ArrayList<MulExp> expressions, String name) {
        super(first, ops, expressions, name);
    }

    public int getArray() {
        return getFirst().getArray();
    }
}
