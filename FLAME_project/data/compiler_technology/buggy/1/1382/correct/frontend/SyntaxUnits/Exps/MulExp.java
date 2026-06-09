package frontend.SyntaxUnits.Exps;


import frontend.Token;

import java.util.ArrayList;

public class MulExp extends Exps<UnaryExp>{
    public MulExp(UnaryExp toBegin,
                  ArrayList<Token> operators,
                  ArrayList<UnaryExp> operands) {
        super(toBegin, operators, operands, "<MulExp>");
    }
}
