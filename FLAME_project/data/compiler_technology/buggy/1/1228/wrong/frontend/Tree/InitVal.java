package frontend.Tree;

import java.util.ArrayList;

public class InitVal {
    private ArrayList<Exp> exps;
    private String stringConst;

    public InitVal(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    public InitVal(String stringConst) {
        this.stringConst = stringConst;
    }
}
