package frontend.parser.expression;

import frontend.parser.SyntaxUnit;
import frontend.parser.expression.lOrExp.LOrExp;

public class Cond implements SyntaxUnit {
    private String name = "<Cond>";
    // Cond â†’ LOrExp
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(lOrExp.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
