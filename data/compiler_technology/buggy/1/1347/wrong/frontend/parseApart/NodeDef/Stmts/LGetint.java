package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Exps.LVal;
import frontend.parseApart.NodeDef.Normal.Stmt;

public class LGetint extends Stmt {

    private LVal lVal;

    public LGetint() {

    }

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public String returnSymbolType() {
        String string = "<Stmt>";
        return string;
    }
}
