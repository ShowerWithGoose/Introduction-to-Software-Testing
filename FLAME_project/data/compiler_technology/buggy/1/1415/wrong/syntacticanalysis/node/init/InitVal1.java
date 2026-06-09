package syntacticanalysis.node.init;

import syntacticanalysis.node.expression.Exp;

public class InitVal1 extends InitVal {
    private String name = "<InitVal>";
    private Exp exp;

    public InitVal1(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.syntaxOutput());
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
