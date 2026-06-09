package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class EqExp extends calculateExp<RelExp>{
    public EqExp(RelExp one, ArrayList<Token> operators, ArrayList<RelExp> operands) {
        super(one, operators, operands, "<EqExp>","RelExp");
    }
}
