package frontend.GrammaticalElements.expression;

import frontend.Token;

import java.util.ArrayList;

public class RelExp extends MultiExp<AddExp>{
    public RelExp(AddExp first, ArrayList<Token> operator, ArrayList<AddExp> operands) {
        super("<RelExp>", first, operator, operands);
    }
}
