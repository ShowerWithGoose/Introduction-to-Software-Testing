package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Exps.Exp;
import frontend.parseApart.NodeDef.Exps.LVal;

public class FirstForStmt {
    private LVal lVal;
    private Exp exp;

    public FirstForStmt() {

    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public String returnSymbolType() {
        String string = "<ForStmt>";
        return string;
    }
}
