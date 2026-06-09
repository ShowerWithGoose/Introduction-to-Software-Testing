package frontend.parser.specificUnit;

import frontend.lexer.Word;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class AddExp extends ParseUnit {
    private ArrayList<MulExp> mulExps;

    public AddExp(String name, ArrayList<ParseUnit> subUnits,
                  ArrayList<MulExp> mulExps) {
        super(name, subUnits);
        this.mulExps = mulExps;
    }

    public Param getParam() {
        if (mulExps.size() > 1) {
            return new Param(Word.INTTK, false);
        } else {
            return mulExps.get(0).getParam();
        }
    }

}
