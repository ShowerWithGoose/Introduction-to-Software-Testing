package AST;

import java.util.ArrayList;

public class AddExp {
    private ArrayList<MulExp> mulExps;
    private ArrayList<String> ops;
    public AddExp(ArrayList<MulExp> mulExps, ArrayList<String> ops) {
        this.mulExps = (mulExps);
        this.ops = (ops);
    }
}
