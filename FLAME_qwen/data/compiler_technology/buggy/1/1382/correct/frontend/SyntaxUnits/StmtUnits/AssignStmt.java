package frontend.SyntaxUnits.StmtUnits;

import frontend.SyntaxUnits.Exp;
import frontend.SyntaxUnits.Exps.LVal;

public class AssignStmt implements StmtUnit{
    private final LVal lVal;
    private final Exp exp;

    public AssignStmt(LVal lVal, Exp exp) {
        this.lVal = lVal;
        this.exp = exp;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(lVal.toPrint());
        stringBuilder.append("ASSIGN" + " =" +  "\n");
        stringBuilder.append(exp.toPrint());
        stringBuilder.append("SEMICN" + " ;" +  "\n");
        return stringBuilder.toString();
    }
}
