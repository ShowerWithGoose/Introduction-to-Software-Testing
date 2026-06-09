package frontend.Parser.Exp.Type.SameExp;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class RelExp extends SameExp<AddExp>{
    public RelExp(ArrayList<AddExp> addExp, ArrayList<LexType> ops) {
        super(addExp, ops);
    }
}
