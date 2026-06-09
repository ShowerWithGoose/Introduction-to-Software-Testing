package parser_part.expression.binaryExpression;

import lexer_part.Token;

import java.util.ArrayList;

public class EqExp extends BinaryExp<RelExp> {
    public EqExp(RelExp first, ArrayList<Token> ops, ArrayList<RelExp> expressions, String name) {
        super(first, ops, expressions, name);
    }
}
