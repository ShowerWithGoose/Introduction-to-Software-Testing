package frontend.SyntaxUnits.StmtUnits;

import frontend.SyntaxUnits.Exp;


public class ExpStmt implements StmtUnit{
    private final Exp exp;

    public ExpStmt(Exp exp) {
        this.exp = exp;
    }

    public ExpStmt() {
        this.exp = null;
    }


    @Override
    public String toPrint() {
        if (exp == null) return "SEMICN" + " ;" +  "\n";
        else return exp.toPrint() + "SEMICN" + " ;" +  "\n";
    }
}
