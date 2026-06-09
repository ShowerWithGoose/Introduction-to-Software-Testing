package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class LAndExp extends calculateExp<EqExp>{

    public LAndExp(EqExp one, ArrayList<Token> operators, ArrayList<EqExp> operands) {
        super(one, operators, operands, "<LAndExp>","<EqExp>");
    }
}
