package parser.block;

import parser.exp.Exp;

import java.util.ArrayList;

public class PrintfStmt implements Stmt {
    private final String stringConst;
    private final ArrayList<Exp> exps;

    public PrintfStmt(String stringConst) {
        this.stringConst = stringConst;
        this.exps = new ArrayList<>();
    }

    public void addExp(Exp exp) {
        this.exps.add(exp);
    }

    public String toString() {
        StringBuilder str = new StringBuilder("PRINTFTK printf\nLPARENT (\n");
        str.append("STRCON " + this.stringConst + "\n");
        for (Exp exp : this.exps) {
            str.append("COMMA ,\n");
            str.append(exp.toString());
        }
        str.append("RPARENT )\nSEMICN ;\n<Stmt>\n");
        return str.toString();
    }
}
