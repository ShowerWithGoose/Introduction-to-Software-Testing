package frontend.parser.specificUnit;

import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class LOrExp extends ParseUnit {
    private ArrayList<LAndExp> lAndExps;

    public LOrExp(String name, ArrayList<ParseUnit> subUnits,
                  ArrayList<LAndExp> lAndExps) {
        super(name, subUnits);
        this.lAndExps = lAndExps;
    }
}
