package frontend.Parser.Class;

import java.util.ArrayList;

public class InitVal {
    Exp exp;
    ArrayList<Exp> exps;
    String stringConst;

    public InitVal(Exp exp, ArrayList<String> outputList) {
        this.exp = exp;
        outputList.add("<InitVal>");
    }

    public InitVal(ArrayList<Exp> exps, ArrayList<String> outputList) {
        this.exps = exps;
        outputList.add("<InitVal>");
    }

    public InitVal(String stringConst, ArrayList<String> outputList) {
        this.stringConst = stringConst;
        outputList.add("<InitVal>");
    }
}
