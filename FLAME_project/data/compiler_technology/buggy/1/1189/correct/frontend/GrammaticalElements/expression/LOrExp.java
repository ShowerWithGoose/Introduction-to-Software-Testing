package frontend.GrammaticalElements.expression;

import java.util.ArrayList;
import frontend.Token;

public class LOrExp extends MultiExp<LAndExp> {
    public LOrExp(LAndExp first, ArrayList<Token> operator, ArrayList<LAndExp> operands) {
        super("<LOrExp>", first, operator, operands);
    }
}
