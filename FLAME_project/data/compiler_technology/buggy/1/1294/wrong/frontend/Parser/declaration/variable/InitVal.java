package frontend.Parser.declaration.variable;

import frontend.Parser.GrammarNode;
import frontend.Parser.expression.Exp;
import frontend.Parser.terminal.StringConst;

public class InitVal implements GrammarNode {
    private final String grammarName = "<InitVal>";
    private Exp exp;
    private ExpArray expArray;
    private StringConst stringConst;

    public InitVal(Exp exp, ExpArray expArray, StringConst stringConst) {
        this.exp = exp;
        this.expArray = expArray;
        this.stringConst = stringConst;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        if (this.exp != null) {
            sb.append(this.exp.grammarOutput());
        } else if (this.expArray != null) {
            sb.append(this.expArray.grammarOutput());
        } else if (this.stringConst != null) {
            sb.append(this.stringConst.getToken().grammarOutput());
        }
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
