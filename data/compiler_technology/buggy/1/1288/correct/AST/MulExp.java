package AST;

import java.util.ArrayList;

public class MulExp {
    private ArrayList<UnaryExp> unaryExps;
    private ArrayList<String> ops;

    public MulExp(ArrayList<UnaryExp> unaryExps, ArrayList<String> ops) {
        this.unaryExps = unaryExps;
        this.ops = ops;
    }
}
