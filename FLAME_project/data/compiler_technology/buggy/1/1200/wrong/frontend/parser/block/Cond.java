package frontend.parser.block;

import frontend.parser.expression.LOrExp;

public class Cond {
    private final String name = "<Cond>";
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public int getLineno() {
        return lOrExp.getLineno();
    }

    public String getOutPut() {
        return lOrExp.getOutPut() + name + "\n";
    }

    public String getError() {
        return lOrExp.getError();
    }
}
