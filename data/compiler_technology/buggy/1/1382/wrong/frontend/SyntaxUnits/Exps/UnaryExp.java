package frontend.SyntaxUnits.Exps;

import frontend.SyntaxUnits.SyntaxUnit;

public class UnaryExp implements SyntaxUnit {
    private final UnaryExpUnit  unaryExpUnit;

    public UnaryExp(UnaryExpUnit unaryExpUnit) {
        this.unaryExpUnit = unaryExpUnit;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(unaryExpUnit.toPrint());
        stringBuilder.append("<UnaryExp>\n");
        return stringBuilder.toString();
    }
}
