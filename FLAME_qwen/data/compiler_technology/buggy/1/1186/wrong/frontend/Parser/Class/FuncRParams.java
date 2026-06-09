package frontend.Parser.Class;

import java.util.ArrayList;

public class FuncRParams {
    private ArrayList<Exp> exps;

    public FuncRParams(ArrayList<Exp> exps, ArrayList<String> outputList) {
        this.exps = exps;
        outputList.add("<FuncRParams>");
    }
}
