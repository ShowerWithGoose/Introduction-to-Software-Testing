package frontend.parser.expression.primaryExp;

import frontend.parser.SyntaxUnit;
import frontend.parser.expression.unaryExp.UnaryExpUnit;

public class PrimaryExp implements UnaryExpUnit {
    private String name = "<PrimaryExp>";
    private PrimaryExpUnit primaryExpUnit;

    public PrimaryExp(PrimaryExpUnit primaryExpUnit) {
        this.primaryExpUnit = primaryExpUnit;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(primaryExpUnit.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
