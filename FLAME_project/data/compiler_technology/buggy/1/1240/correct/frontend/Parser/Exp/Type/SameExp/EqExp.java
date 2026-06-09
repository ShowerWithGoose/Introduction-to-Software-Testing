package frontend.Parser.Exp.Type.SameExp;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class EqExp extends SameExp<RelExp>{
    public EqExp(ArrayList<RelExp> relExps, ArrayList<LexType> ops) {
        super(relExps, ops);
    }
}
