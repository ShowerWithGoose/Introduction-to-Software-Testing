package frontend.Parser.Exp;

import frontend.Token;

import java.util.ArrayList;

public class LOrExp extends BinaryExp<LAndExp>{
    public LOrExp(LAndExp first, ArrayList<Token> op, ArrayList<LAndExp> others) {
        super("<LOrExp>", first, op, others);
    }
}
