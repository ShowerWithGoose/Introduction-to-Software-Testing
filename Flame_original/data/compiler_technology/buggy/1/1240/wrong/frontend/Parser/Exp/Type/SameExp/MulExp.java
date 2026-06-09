package frontend.Parser.Exp.Type.SameExp;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.UnaryExp;

import java.util.ArrayList;

public class MulExp extends SameExp<UnaryExp>{
    public MulExp(ArrayList<UnaryExp> unaryExps, ArrayList<LexType> ops) {
        super(unaryExps, ops);
    }
}
