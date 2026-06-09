package frontend.parser.specificUnit;

import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class LAndExp extends ParseUnit {
    private ArrayList<EqExp> eqExps;

    public LAndExp(String name, ArrayList<ParseUnit> subUnits,
                   ArrayList<EqExp> eqExps) {
        super(name, subUnits);
        this.eqExps = eqExps;
    }
}
