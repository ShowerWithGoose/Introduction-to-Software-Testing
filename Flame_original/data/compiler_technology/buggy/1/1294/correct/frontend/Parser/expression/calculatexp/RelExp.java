package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class RelExp extends calculateExp<AddExp>{
    public RelExp(AddExp one, ArrayList<Token> operators, ArrayList<AddExp> operands) {
        super(one, operators, operands, "<RelExp>","<AddExp>");
    }
}
