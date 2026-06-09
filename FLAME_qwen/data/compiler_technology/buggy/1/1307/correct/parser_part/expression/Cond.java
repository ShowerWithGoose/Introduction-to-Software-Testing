package parser_part.expression;

import parser_part.Node;
import parser_part.expression.binaryExpression.LOrExp;

public class Cond implements Node {
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String toString() {
        return lOrExp.toString() + "<Cond>\n";
    }

}
