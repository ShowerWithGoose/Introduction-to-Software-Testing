package frontend.SyntaxUnits.Exps;

import frontend.SyntaxUnits.SyntaxUnit;
import frontend.Token;

import java.util.ArrayList;

public class EqExp extends Exps<RelExp> {

    public EqExp(RelExp toBegin,
                  ArrayList<Token> operators,
                  ArrayList<RelExp> operands) {
        super(toBegin, operators, operands, "<EqExp>");
    }
}
