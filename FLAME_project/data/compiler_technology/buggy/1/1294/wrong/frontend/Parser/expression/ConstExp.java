package frontend.Parser.expression;

import frontend.Parser.expression.calculatexp.AddExp;

public class ConstExp {
    private final String grammarName = "<ConstExp>";
    private AddExp addExp;
    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String grammarOutput(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.addExp.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
