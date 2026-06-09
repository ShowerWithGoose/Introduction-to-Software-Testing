package frontend.parser.specificUnit;

import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class Exp extends ParseUnit {
    private AddExp addExp;

    public Exp(String name, ArrayList<ParseUnit> subUnits, AddExp addExp) {
        super(name, subUnits);
        this.addExp = addExp;
    }

    public Param getParam() {
        return addExp.getParam();
    }
}
