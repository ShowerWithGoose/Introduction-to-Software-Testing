package frontend.Parser.Exp;

import frontend.Token;

import java.util.ArrayList;

public class RelExp extends BinaryExp<AddExp> {
    public RelExp(AddExp first, ArrayList<Token> op, ArrayList<AddExp> others) {
        super("<RelExp>", first, op, others);
    }
}
