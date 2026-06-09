package syntaxTree;

public class AssignStmt extends Stmt {
    final LVal lVal;
    final Exp exp;

    public AssignStmt(LVal lVal, Exp exp) {
        this.lVal = lVal;
        this.exp = exp;
    }
}
