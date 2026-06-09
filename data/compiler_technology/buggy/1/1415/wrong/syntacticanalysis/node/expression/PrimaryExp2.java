package syntacticanalysis.node.expression;

import syntacticanalysis.node.LVal;

public class PrimaryExp2 extends PrimaryExp {
    private String name = "<PrimaryExp>";
    private LVal lval;

    public PrimaryExp2(LVal lval) {
        this.lval = lval;
    }

    @Override
    public String syntaxOutput() {
        return lval.syntaxOutput() + "\n" + name;
    }
}
