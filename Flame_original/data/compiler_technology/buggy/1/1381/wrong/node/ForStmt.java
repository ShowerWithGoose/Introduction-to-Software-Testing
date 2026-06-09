package node;

import frontend.Parser;

public class ForStmt {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.ForStmt;
    private LVal lval;
    private Exp exp;

    public ForStmt(LVal lval, Exp exp) {
        this.lval = lval;
        this.exp = exp;
    }

    public LVal getLVal() {
        return lval;
    }

    public Exp getExp() {
        return exp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(lval.toString());
        ret.append("\n").append(exp.toString());
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
