package frontend.SyntaxUnits;

import frontend.SyntaxUnits.Exps.LVal;

public class ForStmt implements SyntaxUnit {
    private final LVal lVal;
    private final Exp exp;

    public ForStmt(LVal lVal, Exp exp) {
        this.exp = exp;
        this.lVal = lVal;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(lVal.toPrint());
        stringBuilder.append("ASSIGN" + " =" +  "\n");
        stringBuilder.append(exp.toPrint());
        stringBuilder.append("<ForStmt>\n");
        return stringBuilder.toString();
    }
}
