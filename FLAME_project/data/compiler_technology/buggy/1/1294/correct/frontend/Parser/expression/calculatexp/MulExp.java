package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

public class MulExp extends calculateExp<UnaryExp>{

    public MulExp(UnaryExp one, ArrayList<Token> operators, ArrayList<UnaryExp> operands) {
        super(one, operators, operands,"<MulExp>","<UnaryExp>");
    }
}
