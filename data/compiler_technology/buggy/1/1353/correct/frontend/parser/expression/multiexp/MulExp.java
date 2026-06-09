package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

/**
 * MulExp 乘除模表达式类
 * 消除左递归文法
 * <MulExp> -> <UnaryExp> | { ('*' | '/' | '%') <UnaryExp> }
 */
public class MulExp extends MultiExp<UnaryExp> {
    public MulExp(UnaryExp first, ArrayList<Token> operators, ArrayList<UnaryExp> operands) {
        super(first, operators, operands, "<MulExp>");
    }
}
