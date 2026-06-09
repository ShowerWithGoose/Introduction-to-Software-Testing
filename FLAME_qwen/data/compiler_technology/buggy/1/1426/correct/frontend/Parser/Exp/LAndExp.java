package frontend.Parser.Exp;

import frontend.Token;

import java.util.ArrayList;

public class LAndExp extends BinaryExp<EqExp> {
    public LAndExp(EqExp first, ArrayList<Token> op, ArrayList<EqExp> others) {
        super("<LAndExp>", first, op, others);
    }
}
