package Fronted.parser.syntax;

import Fronted.lexer.Token;

// ForStmt â†’ LVal '=' Exp
public class ForStmt {
    private static final String name = "<ForStmt>";

    private LVal lVal = null;

    private Token assign = null;

    private Exp exp = null;

    public ForStmt(LVal lVal, Token assign, Exp exp) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(lVal).append(assign).append(exp);
        out.append(name).append("\n");
        return out.toString();
    }

    public LVal getLVal() {
        return lVal;
    }

    public Token getAssign() {
        return assign;
    }

    public Exp getExp() {
        return exp;
    }

    public void setLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setAssign(Token assign) {
        this.assign = assign;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }
}
