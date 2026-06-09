package frontend.SyntaxUnits.Exps;

import frontend.SyntaxUnits.SyntaxUnit;
import frontend.Token;

import java.util.ArrayList;

public class AddExp extends Exps<MulExp>{

    public AddExp(MulExp toBegin,
                  ArrayList<Token> operators,
                  ArrayList<MulExp> operands) {
        super(toBegin, operators, operands, "<AddExp>");
    }
}
