package frontend.GrammaticalElements.expression;

import frontend.Token;

import java.util.ArrayList;

public class AddExp extends MultiExp<MulExp>{

    public AddExp(MulExp first, ArrayList<Token> operator, ArrayList<MulExp> operands) {
        super("<AddExp>", first, operator, operands);
    }
}
