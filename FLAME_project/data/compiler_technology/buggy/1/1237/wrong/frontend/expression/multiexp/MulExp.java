package frontend.expression.multiexp;

import java.util.List;

import frontend.Token;
import frontend.expression.unaryexp.UnaryExp;

public class MulExp extends MultiExp<UnaryExp> {
    public MulExp(UnaryExp first, List<Token> operators, List<UnaryExp> operands) {
        super(first, operators, operands, "<MulExp>");
    }
}