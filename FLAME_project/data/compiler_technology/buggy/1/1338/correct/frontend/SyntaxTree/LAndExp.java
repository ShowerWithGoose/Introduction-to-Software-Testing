package frontend.SyntaxTree;

import java.util.ArrayList;

public class LAndExp {
    private ArrayList<EqExp> eqExps;

    public LAndExp() {
        eqExps = new ArrayList<EqExp>();
    }

    public void addEqExp(EqExp eqExp) {
        eqExps.add(eqExp);
    }
}
