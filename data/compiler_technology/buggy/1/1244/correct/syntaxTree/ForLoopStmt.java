package syntaxTree;

public class ForLoopStmt extends Stmt {
    private final ForStmt initStmt;
    private final Cond cond;
    private final ForStmt iterStmt;
    private final Stmt stmt;

    public ForLoopStmt(ForStmt initStmt, Cond cond, ForStmt iterStmt, Stmt stmt) {
        this.initStmt = initStmt;
        this.cond = cond;
        this.iterStmt = iterStmt;
        this.stmt = stmt;
    }
}
