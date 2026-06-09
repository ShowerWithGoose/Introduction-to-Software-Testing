package frontend.Parser.Class;

import java.util.ArrayList;

public class Cond {
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp, ArrayList<String> outputList) {
        this.lOrExp = lOrExp;
        outputList.add("<Cond>");
    }
}
