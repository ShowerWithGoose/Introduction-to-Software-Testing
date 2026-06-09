package frontend.Nodes;

import frontend.Token;

public class FuncFParam implements Node {
    private BType bType;
    private Token ident;
    private Token lBrack;
    private Token rBrack;

    public FuncFParam() {
        this.bType = null;
        this.ident = null;
        this.lBrack = null;
        this.rBrack = null;
    }

    public void addBType(BType bType) {
        this.bType = bType;
    }

    public void addIdent(Token ident) {
        this.ident = ident;
    }

    public void addLBrack(Token lBrack) {
        this.lBrack = lBrack;
    }

    public void addRBrack(Token rBrack) {
        this.rBrack = rBrack;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        if (bType != null) {
            sb.append(bType.error());
        }
        if (ident != null) {
            sb.append(ident.error());
        }
        if (lBrack != null) {
            sb.append(lBrack.error());
        }
        if (rBrack != null) {
            sb.append(rBrack.error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (bType != null) {
            sb.append(bType.toString());
        }
        if (ident != null) {
            sb.append(ident.toString());
        }
        if (lBrack != null) {
            sb.append(lBrack.toString());
        }
        if (rBrack != null) {
            sb.append(rBrack.toString());
        }
        sb.append("<FuncFParam>\n");
        return sb.toString();
    }
}
