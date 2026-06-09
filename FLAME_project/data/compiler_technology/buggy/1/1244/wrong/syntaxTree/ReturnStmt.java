package syntaxTree;

public class ReturnStmt extends Stmt {
    private final Exp exp;

    public ReturnStmt(Exp exp) {
        this.exp = exp;
    }
}
