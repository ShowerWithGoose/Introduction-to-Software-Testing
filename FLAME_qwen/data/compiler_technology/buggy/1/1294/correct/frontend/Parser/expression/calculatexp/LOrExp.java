package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class LOrExp extends calculateExp<LAndExp>{
    public LOrExp(LAndExp one, ArrayList<Token> operators, ArrayList<LAndExp> operands) {
        super(one, operators, operands, "<LOrExp>","<LAndExp>");
    }
}
