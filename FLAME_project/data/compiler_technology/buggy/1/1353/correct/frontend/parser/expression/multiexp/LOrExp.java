package frontend.parser.expression.multiexp;

import frontend.lexer.Token;

import java.util.ArrayList;

/**
 * LOrExp 逻辑或表达式类
 * 消除左递归文法
 * <LOrExp> -> <LAndExp> { '&&' <LAndExp> }
 */
public class LOrExp extends MultiExp<LAndExp> {
    public LOrExp(LAndExp first, ArrayList<Token> operators,
                  ArrayList<LAndExp> operands) {
        super(first, operators, operands, "<LOrExp>");
    }
}
