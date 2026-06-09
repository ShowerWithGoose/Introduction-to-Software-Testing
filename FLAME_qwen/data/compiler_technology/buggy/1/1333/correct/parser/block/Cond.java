package parser.block;

import parser.exp.LOrExp;

public class Cond {
    private final LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public String toString() {
        return this.lOrExp.toString() + "<Cond>\n";
    }
}
