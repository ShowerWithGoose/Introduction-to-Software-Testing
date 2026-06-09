package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class AddExp extends calculateExp<MulExp>{
    public AddExp(MulExp theOne, ArrayList<Token> operators, ArrayList<MulExp> operands) {
        super(theOne, operators, operands,"<AddExp>","<MulExp>");
    }

}
