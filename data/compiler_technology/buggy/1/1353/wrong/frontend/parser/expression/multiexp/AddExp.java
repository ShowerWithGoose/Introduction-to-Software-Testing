package frontend.parser.expression.multiexp;

import frontend.lexer.Token;

import java.util.ArrayList;

/**
 * AddExp 加减表达式类
 * 消除左递归文法
 * <AddExp> -> <MulExp> { ('+' | '-') <MulExp> }
 */
public class AddExp extends MultiExp<MulExp> {
    public AddExp(MulExp first, ArrayList<Token> tokens, ArrayList<MulExp> operands) {
        super(first, tokens, operands, "<AddExp>");
    }
}
