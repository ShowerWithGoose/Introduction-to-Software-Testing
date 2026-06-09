package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Exps.Exp;
import frontend.parseApart.NodeDef.Exps.LVal;
import frontend.parseApart.NodeDef.Normal.Stmt;

public class LEStmt extends Stmt {

    private LVal lVal;
    private Exp exp;

    public LEStmt() {}

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public String returnSymbolType() {
        String string = "<Stmt>";
        return string;
    }
}
