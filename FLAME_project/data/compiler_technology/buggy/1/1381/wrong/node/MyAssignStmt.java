package node;

import frontend.Token;

public class MyAssignStmt extends Stmt {
    private LVal lVal;
    private Exp exp;

    public MyAssignStmt(LVal lVal, Exp exp) {
        super(Token.TokenType.ASSIGN);
        this.lVal = lVal;
        this.exp = exp;
    }

    public LVal getLVal() {
        return lVal;
    }

    public Exp getExp() {
        return exp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + getNodeType() + ">");
        ret.append("\n").append(getType());
        ret.append("\n").append(lVal);
        ret.append("\n").append(exp);
        ret.append("\n<").append(getNodeType()).append("> <END>");
        return ret.toString();
    }
}