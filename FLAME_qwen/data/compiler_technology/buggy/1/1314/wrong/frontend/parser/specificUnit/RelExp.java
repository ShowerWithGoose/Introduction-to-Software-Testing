package frontend.parser.specificUnit;

import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class RelExp extends ParseUnit {
    private ArrayList<AddExp> addExps;

    public RelExp(String name, ArrayList<ParseUnit> subUnits,
                  ArrayList<AddExp> addExps) {
        super(name, subUnits);
        this.addExps = addExps;
    }
}
