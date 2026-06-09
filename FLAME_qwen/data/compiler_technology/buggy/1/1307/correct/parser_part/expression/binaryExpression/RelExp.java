package parser_part.expression.binaryExpression;

import lexer_part.Token;

import java.util.ArrayList;

public class RelExp extends BinaryExp<AddExp> {

    public RelExp(AddExp first, ArrayList<Token> ops, ArrayList<AddExp> expressions, String name) {
        super(first, ops, expressions, name);
    }
}
