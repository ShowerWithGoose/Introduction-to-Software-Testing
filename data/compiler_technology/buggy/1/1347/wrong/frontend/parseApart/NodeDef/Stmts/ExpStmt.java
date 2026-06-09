package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Exps.Exp;
import frontend.parseApart.NodeDef.Normal.Stmt;

public class ExpStmt extends Stmt {
    private Exp exp = null;

    public ExpStmt() {}

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public String returnSymbolType() {
        String string = "<Stmt>";
        return string;
    }
}
