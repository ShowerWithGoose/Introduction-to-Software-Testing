package frontend.GrammaticalElements.expression;

import frontend.Token;

import java.util.ArrayList;

public class LAndExp extends MultiExp<EqExp>{
    public LAndExp(EqExp first, ArrayList<Token> operator, ArrayList<EqExp> operands) {
        super("<LAndExp>", first, operator, operands);
    }
}
