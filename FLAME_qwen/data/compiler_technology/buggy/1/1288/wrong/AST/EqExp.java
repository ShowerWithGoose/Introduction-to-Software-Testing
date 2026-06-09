package AST;

import java.util.ArrayList;

public class EqExp {
    private ArrayList<RelExp> relExps;
    private ArrayList<String> ops;

    public EqExp(ArrayList<RelExp> relExps, ArrayList<String> ops) {
        this.relExps=(relExps);
        this.ops=(ops);
    }
}
