package syntacticanalysis.node.stmts;

import syntacticanalysis.node.expression.LOrExp;

public class Cond {
    private String name = "<Cond>";
    private LOrExp lorExp;

    public Cond(LOrExp lorExp) {
        this.lorExp = lorExp;
    }

    public String syntaxOutput() {
        return lorExp.syntaxOutput() + "\n" + name;
    }
}
