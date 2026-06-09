package AST;

import java.util.ArrayList;

public class ConstInitVal {
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    private ConstExp constExp;

    private StringConst stringConst;

    public ConstInitVal(ArrayList<ConstExp> constExps, ConstExp constExp, StringConst stringConst) {
        this.constExps=(constExps);
        this.constExp = constExp;
        this.stringConst = stringConst;
    }
}
