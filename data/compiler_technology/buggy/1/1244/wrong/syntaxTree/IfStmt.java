package syntaxTree;

public class IfStmt extends Stmt {
    private final Cond cond;
    private final Stmt stmt;
    private final Stmt elseStmt;

    public IfStmt(Cond cond, Stmt stmt, Stmt elseStmt) {
        this.cond = cond;
        this.stmt = stmt;
        this.elseStmt = elseStmt;
    }
}
