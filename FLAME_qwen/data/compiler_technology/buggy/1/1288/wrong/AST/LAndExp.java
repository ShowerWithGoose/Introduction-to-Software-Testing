package AST;

import java.util.ArrayList;

public class LAndExp {
    private ArrayList<EqExp> eqExps;
    private ArrayList<String> ops;

    public LAndExp(ArrayList<EqExp> eqExps, ArrayList<String> ops) {
        this.eqExps=(eqExps);
        this.ops=(ops);
    }
}
