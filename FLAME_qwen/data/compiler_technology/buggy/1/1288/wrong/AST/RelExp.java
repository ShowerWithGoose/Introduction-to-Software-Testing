package AST;

import java.util.ArrayList;

public class RelExp {
    private ArrayList<AddExp> addExps;
    private ArrayList<String> ops;

    public RelExp(ArrayList<AddExp> addExps, ArrayList<String> ops) {
        this.addExps=(addExps);
        this.ops=(ops);
    }
}
