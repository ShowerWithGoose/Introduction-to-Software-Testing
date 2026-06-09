package frontend.SyntaxUnits.Exps;

import frontend.SyntaxUnits.SyntaxUnit;

public class PrimaryExp implements UnaryExpUnit{
    private final PrimaryExpUnit primaryExpUnit;

    public PrimaryExp(PrimaryExpUnit primaryExpUnit) {
        this.primaryExpUnit = primaryExpUnit;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(primaryExpUnit.toPrint());
        stringBuilder.append("<PrimaryExp>\n");
        return stringBuilder.toString();
    }
}
