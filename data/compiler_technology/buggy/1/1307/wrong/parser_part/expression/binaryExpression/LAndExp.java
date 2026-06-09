package parser_part.expression.binaryExpression;

import lexer_part.Token;

import java.util.ArrayList;

public class LAndExp extends BinaryExp<EqExp> {
    public LAndExp(EqExp first, ArrayList<Token> ops, ArrayList<EqExp> expressions, String name) {
        super(first, ops, expressions, name);
    }
}
