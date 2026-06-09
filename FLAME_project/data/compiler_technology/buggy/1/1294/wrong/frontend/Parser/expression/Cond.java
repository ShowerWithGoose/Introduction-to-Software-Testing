package frontend.Parser.expression;

import frontend.Parser.GrammarNode;
import frontend.Parser.expression.calculatexp.LOrExp;

//条件表达式 Cond -> LOrExp
public class Cond implements GrammarNode {
    private final String grammarName = "<Cond>";
    private LOrExp lOrExp;
    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lOrExp.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
