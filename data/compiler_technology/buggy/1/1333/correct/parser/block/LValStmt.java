package parser.block;

import parser.exp.Exp;
import parser.exp.LVal;

public class LValStmt implements Stmt {
    private final LVal lVal;
    private final Exp exp;

    public LValStmt(LVal lVal, Exp exp) {
        this.lVal = lVal;
        this.exp = exp;
    }

    public String toString() {
        return this.lVal.toString() + "ASSIGN =\n" + this.exp.toString() + "SEMICN ;\n<Stmt>\n";
    }
}
