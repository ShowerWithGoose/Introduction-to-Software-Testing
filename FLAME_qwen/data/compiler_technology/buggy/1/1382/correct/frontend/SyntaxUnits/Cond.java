package frontend.SyntaxUnits;

import frontend.SyntaxUnits.Exps.LOrExp;

public class Cond implements SyntaxUnit {
    private final LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(lOrExp.toPrint());
        stringBuilder.append("<Cond>\n");
        return stringBuilder.toString();
    }
}
