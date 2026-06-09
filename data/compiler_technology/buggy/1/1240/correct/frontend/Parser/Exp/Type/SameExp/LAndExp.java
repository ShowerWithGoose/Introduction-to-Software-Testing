package frontend.Parser.Exp.Type.SameExp;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class LAndExp extends SameExp<EqExp>{
    public LAndExp(ArrayList<EqExp> eqExps, ArrayList<LexType> ops) {
        super(eqExps, ops);
    }
}
