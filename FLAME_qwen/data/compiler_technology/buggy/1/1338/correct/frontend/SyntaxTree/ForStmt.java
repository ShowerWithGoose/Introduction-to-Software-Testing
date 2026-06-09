package frontend.SyntaxTree;

public class ForStmt {
    private LVal lVal;
    private Exp exp;

    public ForStmt() {
    }

    public void setLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }
}
