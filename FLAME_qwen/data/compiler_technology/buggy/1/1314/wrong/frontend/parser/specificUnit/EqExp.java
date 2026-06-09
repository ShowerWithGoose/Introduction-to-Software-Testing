package frontend.parser.specificUnit;

import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class EqExp extends ParseUnit {
    private ArrayList<RelExp> relExps;

    public EqExp(String name, ArrayList<ParseUnit> subUnits,
                 ArrayList<RelExp> relExps) {
        super(name, subUnits);
        this.relExps = relExps;
    }
}
