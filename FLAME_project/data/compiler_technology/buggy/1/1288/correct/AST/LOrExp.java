package AST;

import java.util.ArrayList;

public class LOrExp {
    private ArrayList<LAndExp> lAndExps;
    private ArrayList<String> ops;

    public LOrExp(ArrayList<LAndExp> lAndExps, ArrayList<String> ops) {
        this.lAndExps=(lAndExps);
        this.ops=(ops);
    }
}
