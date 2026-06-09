package parser.block;

import parser.exp.Exp;

public class ReturnStmt implements Stmt {
    private final Exp exp;

    public ReturnStmt(Exp exp) {
        this.exp = exp;
    }

    public String toString() {
        StringBuilder str = new StringBuilder("RETURNTK return\n");
        if (this.exp != null) {
            str.append(this.exp.toString());
        }
        str.append("SEMICN ;\n<Stmt>\n");
        return str.toString();
    }
}
