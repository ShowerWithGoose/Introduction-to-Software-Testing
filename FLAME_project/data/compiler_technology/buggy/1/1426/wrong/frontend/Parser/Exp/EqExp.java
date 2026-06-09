package frontend.Parser.Exp;

import frontend.Token;

import java.util.ArrayList;

public class EqExp extends BinaryExp<RelExp> {
    public EqExp(RelExp first, ArrayList<Token> op, ArrayList<RelExp> others) {
        super("<EqExp>", first, op, others);
    }
}
