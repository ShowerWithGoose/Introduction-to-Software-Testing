package frontend.Nodes;

import frontend.Token;

public class ForStmt implements Node {
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmt() {
        this.lVal = null;
        this.assign = null;
        this.exp = null;
    }

    public void addLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void addAssign(Token assign) {
        this.assign = assign;
    }

    public void addExp(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        if (lVal != null) {
            sb.append(lVal.error());
        }
        if (assign != null) {
            sb.append(assign.error());
        }
        if (exp != null) {
            sb.append(exp.error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (lVal != null) {
            sb.append(lVal.toString());
        }
        if (assign != null) {
            sb.append(assign.toString());
        }
        if (exp != null) {
            sb.append(exp.toString());
        }
        sb.append("<ForStmt>\n");
        return sb.toString();
    }
}
