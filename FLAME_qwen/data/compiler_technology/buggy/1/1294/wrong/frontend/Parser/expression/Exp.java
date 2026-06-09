package frontend.Parser.expression;

import frontend.Parser.GrammarNode;
import frontend.Parser.expression.calculatexp.AddExp;

public class Exp implements GrammarNode {
    private final String grammarName = "<Exp>";
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.addExp.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
