package parser.block;

import parser.exp.Exp;

public class ExpStmt implements Stmt {
    private final Exp exp;

    public ExpStmt(Exp exp) {
        this.exp = exp;
    }

    public String toString() {
        if (this.exp != null) {
            return this.exp.toString() + "SEMICN ;\n<Stmt>\n";
        }
        return "SEMICN ;\n<Stmt>\n";
    }
}
