package frontend.parser.specificUnit;

import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class FuncRParams extends ParseUnit {
    private ArrayList<Exp> rArgs;

    public FuncRParams(String name, ArrayList<ParseUnit> subUnits,
                       ArrayList<Exp> rArgs) {
        super(name, subUnits);
        this.rArgs = rArgs;
    }

    public int getRParamNum() {
        return rArgs.size();
    }

    public ArrayList<Param> getParams() {
        ArrayList<Param> rParams = new ArrayList<>();
        for (int i = 0; i < rArgs.size(); i++) {
            rParams.add(rArgs.get(i).getParam());
        }
        return rParams;
    }
}
