package frontend.parser.expression.multiexp;

import frontend.lexer.Token;

import java.util.ArrayList;

/**
 * RelExp 关系表达式类
 * 消除左递归文法
 * <RelExp> -> <AddExp> { ('<' | '>' | '<=' | '>=') <AddExp> }
 */
public class RelExp extends MultiExp<AddExp> {
    public RelExp(AddExp first, ArrayList<Token> operators, ArrayList<AddExp> operands) {
        super(first, operators, operands, "<RelExp>");
    }
}
