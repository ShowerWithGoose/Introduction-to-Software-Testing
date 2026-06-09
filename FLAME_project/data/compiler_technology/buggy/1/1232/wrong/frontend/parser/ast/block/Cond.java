package frontend.parser.ast.block;

import frontend.parser.ast.exp.LOrExp;

public class Cond {
    private String type = "<Cond>";
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public int getLineno() {
        return lOrExp.getLineno();
    }

    public String getOutput() {
        return lOrExp.getOutput() + type + "\n";
    }

    public String getError() {
        return lOrExp.getError();
    }
}
