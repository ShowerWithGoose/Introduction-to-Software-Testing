package frontend.SyntaxUnits.Exps;
import frontend.Token;

import java.util.ArrayList;

public class LOrExp extends Exps<LAndExp> {

    public LOrExp(LAndExp toBegin,
                  ArrayList<Token> operators,
                  ArrayList<LAndExp> operands) {
        super(toBegin, operators, operands, "<LOrExp>");
    }
}
