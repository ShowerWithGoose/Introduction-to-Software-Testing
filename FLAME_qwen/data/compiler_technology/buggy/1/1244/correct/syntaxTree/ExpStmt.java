package syntaxTree;

public class ExpStmt extends Stmt {
    private final Exp exp;

    public ExpStmt(Exp exp) {
        this.exp = exp;
    }
}
