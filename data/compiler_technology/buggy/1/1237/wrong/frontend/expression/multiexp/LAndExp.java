package frontend.expression.multiexp;

import frontend.Token;

import java.util.ArrayList;

public class LAndExp extends MultiExp<EqExp> {
    public LAndExp(EqExp first, ArrayList<Token> operators,
                   ArrayList<EqExp> operands) {
        super(first, operators, operands, "<LAndExp>");
    }
}