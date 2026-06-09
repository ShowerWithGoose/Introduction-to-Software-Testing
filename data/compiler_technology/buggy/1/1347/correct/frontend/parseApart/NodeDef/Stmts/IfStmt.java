package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Exps.Cond;
import frontend.parseApart.NodeDef.Normal.Stmt;

public class IfStmt extends Stmt {
    private Cond cond;
    private Stmt stmt1 = null;
    private Stmt stmt2 = null;

    public IfStmt() {}

    public void setCond(Cond cond) {
        this.cond = cond;
    }

    public void setStmt1(Stmt stmt1) {
        this.stmt1 = stmt1;
    }

    public void setStmt2(Stmt stmt2) {
        this.stmt2 = stmt2;
    }

    public String returnSymbolType() {
        String string = "<Stmt>";
        return string;
    }

}
