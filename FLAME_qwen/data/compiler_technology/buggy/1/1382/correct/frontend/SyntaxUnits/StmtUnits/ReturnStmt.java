package frontend.SyntaxUnits.StmtUnits;

import frontend.SyntaxUnits.Exp;


public class ReturnStmt implements StmtUnit {
    private final Exp exp;
    private final boolean hasExp;

    public ReturnStmt(){
        exp = null;
        hasExp = false;
    }

    public ReturnStmt(Exp exp) {
        this.exp = exp;
        hasExp = true;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("RETURNTK" + " return" +  "\n");
        if (hasExp) {
            stringBuilder.append(exp.toPrint());
        }
        stringBuilder.append("SEMICN" + " ;" +  "\n");
        return stringBuilder.toString();
    }
}
