package frontend.SyntaxUnits.Exps;
import frontend.Token;

import java.util.ArrayList;

public class LAndExp extends Exps<EqExp> {

    public LAndExp(EqExp toBegin,
                  ArrayList<Token> operators,
                  ArrayList<EqExp> operands) {
        super(toBegin, operators, operands, "<LAndExp>");
    }
}
