package frontend.SyntaxUnits.Exps;
import frontend.Token;

import java.util.ArrayList;

public class RelExp extends Exps<AddExp> {

    public RelExp(AddExp toBegin,
                  ArrayList<Token> operators,
                  ArrayList<AddExp> operands) {
        super(toBegin, operators, operands, "<RelExp>");
    }

}
