package frontend.Parser.Exp.Type.SameExp;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class LOrExp extends SameExp<LAndExp> {
    public LOrExp(ArrayList<LAndExp> lAndExps, ArrayList<LexType> ops) {
        super(lAndExps, ops);
    }
}
