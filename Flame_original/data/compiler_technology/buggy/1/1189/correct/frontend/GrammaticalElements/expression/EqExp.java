package frontend.GrammaticalElements.expression;

import frontend.Token;

import java.util.ArrayList;

public class EqExp extends MultiExp<RelExp>{
    public EqExp(RelExp first, ArrayList<Token> operator, ArrayList<RelExp> operands) {
        super("<EqExp>", first, operator, operands);
    }
}
