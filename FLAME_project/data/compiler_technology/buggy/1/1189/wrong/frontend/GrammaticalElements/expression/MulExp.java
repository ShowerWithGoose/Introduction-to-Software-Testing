package frontend.GrammaticalElements.expression;

import frontend.Token;

import java.util.ArrayList;

public class MulExp extends MultiExp<UnaryExp>{

    public MulExp(UnaryExp first, ArrayList<Token> operator, ArrayList<UnaryExp> operands) {
        super("<MulExp>", first, operator, operands);
    }
}
