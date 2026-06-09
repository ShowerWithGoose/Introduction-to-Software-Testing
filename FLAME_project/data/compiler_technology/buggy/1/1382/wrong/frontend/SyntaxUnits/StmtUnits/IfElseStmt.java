package frontend.SyntaxUnits.StmtUnits;

import frontend.SyntaxUnits.Cond;
import frontend.SyntaxUnits.Stmt;

public class IfElseStmt implements StmtUnit{
    private final Cond cond;
    private final Stmt ifStmt;
    private final Stmt elseStmt;
    private final boolean hasElse;

    public IfElseStmt(Cond cond, Stmt stmt) {
        this.cond = cond;
        this.ifStmt = stmt;
        elseStmt = null;
        hasElse = false;
    }

    public IfElseStmt(Cond cond, Stmt ifStmt, Stmt elseStmt) {
        this.cond = cond;
        this.ifStmt = ifStmt;
        this.elseStmt = elseStmt;
        hasElse = true;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("IFTK" + " if" +  "\n");
        stringBuilder.append("LPARENT" + " (" +  "\n");
        stringBuilder.append(cond.toPrint());
        stringBuilder.append("RPARENT" + " )" +  "\n");
        stringBuilder.append(ifStmt.toPrint());
        if (hasElse) {
            stringBuilder.append("ELSETK" + " else" +  "\n");
            stringBuilder.append(elseStmt.toPrint());
        }
        return stringBuilder.toString();
    }
}
