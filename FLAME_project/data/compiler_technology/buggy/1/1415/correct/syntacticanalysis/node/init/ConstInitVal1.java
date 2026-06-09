package syntacticanalysis.node.init;

import syntacticanalysis.node.expression.ConstExp;

public class ConstInitVal1 extends ConstInitVal {
    private String name = "<ConstInitVal>";
    private ConstExp constExp;

    public ConstInitVal1(ConstExp constExp) {
        this.constExp = constExp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(constExp.syntaxOutput());
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
