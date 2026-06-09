package frontend.Nodes;

import frontend.Token;

public class LVal implements Node {
    private Token ident;
    private Token lBrack;
    private Exp exp;
    private Token rBrack;

    public LVal() {
        this.ident = null;
        this.lBrack = null;
        this.exp = null;
        this.rBrack = null;
    }

    public void addIdent(Token ident) {
        this.ident = ident;
    }

    public void addLBrack(Token lBrack) {
        this.lBrack = lBrack;
    }

    public void addExp(Exp exp) {
        this.exp = exp;
    }

    public void addRBrack(Token rBrack) {
        this.rBrack = rBrack;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        if (ident != null) {
            sb.append(ident.error());
        }
        if (lBrack != null) {
            sb.append(lBrack.error());
        }
        if (exp != null) {
            sb.append(exp.error());
        }
        if (rBrack != null) {
            sb.append(rBrack.error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (ident != null) {
            sb.append(ident.toString());
        }
        if (lBrack != null) {
            sb.append(lBrack.toString());
        }
        if (exp != null) {
            sb.append(exp.toString());
        }
        if (rBrack != null) {
            sb.append(rBrack.toString());
        }
        sb.append("<LVal>\n");
        return sb.toString();
    }
}
