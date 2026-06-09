package frontend.Tree;

import java.util.ArrayList;

public class ConstInitVal {
    private ArrayList<ConstExp> constExps;
    private String stringConst;

    public ConstInitVal(ArrayList<ConstExp> constExps) {
        this.constExps = constExps;
    }

    public ConstInitVal(String stringConst) {
        this.stringConst = stringConst;
    }

}
