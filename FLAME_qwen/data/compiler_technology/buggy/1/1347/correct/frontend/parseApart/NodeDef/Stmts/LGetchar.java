package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Exps.LVal;
import frontend.parseApart.NodeDef.Normal.Stmt;

public class LGetchar extends Stmt {

    private LVal lVal;

    public LGetchar() {}

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public String returnSymbolType() {
        String string = "<Stmt>";
        return string;
    }
}
