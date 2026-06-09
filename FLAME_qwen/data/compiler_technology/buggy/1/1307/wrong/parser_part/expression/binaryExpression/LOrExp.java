package parser_part.expression.binaryExpression;

import lexer_part.Token;

import java.util.ArrayList;
public class LOrExp extends BinaryExp<LAndExp> {
    public LOrExp(LAndExp first, ArrayList<Token> ops, ArrayList<LAndExp> expressions, String name) {
        super(first, ops, expressions, name);
    }
}
