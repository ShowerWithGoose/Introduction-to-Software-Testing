package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Exps.Exp;
import frontend.parseApart.NodeDef.Normal.Stmt;

import java.util.ArrayList;

public class PrintfStmt extends Stmt {

    private String string;
    private ArrayList<Exp> exps = new ArrayList<>();

    public PrintfStmt() {}

    public void setString(String string) {
        this.string = string;
    }

    public void setExps(Exp exp) {
        this.exps.add(exp);
    }

    public String returnSymbolType() {
        String string = "<Stmt>";
        return string;
    }
}
