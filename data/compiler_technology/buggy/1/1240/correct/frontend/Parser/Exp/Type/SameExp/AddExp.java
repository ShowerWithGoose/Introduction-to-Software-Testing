package frontend.Parser.Exp.Type.SameExp;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class AddExp extends SameExp<MulExp> {
    public AddExp(ArrayList<MulExp> mulExps, ArrayList<LexType> ops) {
        super(mulExps, ops);
    }
}
