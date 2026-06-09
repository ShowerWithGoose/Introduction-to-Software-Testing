package frontend.parser.specificUnit;

import frontend.lexer.Word;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class MulExp extends ParseUnit {
    private ArrayList<UnaryExp> unaryExps;

    public MulExp(String name, ArrayList<ParseUnit> subUnits,
                  ArrayList<UnaryExp> unaryExps) {
        super(name, subUnits);
        this.unaryExps = unaryExps;
    }

    public Param getParam() {
        if (unaryExps.size() > 1) {
            return new Param(Word.INTTK, false);
        } else {
            return unaryExps.get(0).getParam();
        }
    }
}
