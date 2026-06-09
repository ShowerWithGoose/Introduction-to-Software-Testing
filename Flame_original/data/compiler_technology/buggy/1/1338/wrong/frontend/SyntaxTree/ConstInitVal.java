package frontend.SyntaxTree;

import java.util.ArrayList;

public class ConstInitVal {
    private ArrayList<ConstExp> constExps;
    private String stringConst;

    public ConstInitVal() {
        this.constExps = new ArrayList<>();
    }

    public void addConstExp(ConstExp constExp) {
        this.constExps.add(constExp);
    }

    public void setStringConst(String stringConst) {
        this.stringConst = stringConst;
    }
}
