package frontend.parser.specificUnit;

import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class Cond extends ParseUnit {
    private LOrExp lOrExp;

    public Cond(String name, ArrayList<ParseUnit> subUnits, LOrExp lOrExp) {
        super(name, subUnits);
        this.lOrExp = lOrExp;
    }
}
