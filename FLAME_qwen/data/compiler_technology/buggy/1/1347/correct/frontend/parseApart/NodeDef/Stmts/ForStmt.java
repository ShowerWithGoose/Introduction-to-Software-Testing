package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Exps.Cond;
import frontend.parseApart.NodeDef.Normal.Stmt;

public class ForStmt extends Stmt {
    private FirstForStmt firstForStmt = null;
    private Cond cond = null;
    private FirstForStmt forStmt2 = null;
    private Stmt stmt;

    public ForStmt() {}

    public void setCond(Cond cond) {
        this.cond = cond;
    }

    public void setFirstForStmt(FirstForStmt firstForStmt) {
        this.firstForStmt = firstForStmt;
    }

    public void setForStmt2(FirstForStmt forStmt2) {
        this.forStmt2 = forStmt2;
    }

    public void setStmt(Stmt stmt) {
        this.stmt = stmt;
    }

    public String returnSymbolType() {
        String string = "<Stmt>";
        return string;
    }
}
