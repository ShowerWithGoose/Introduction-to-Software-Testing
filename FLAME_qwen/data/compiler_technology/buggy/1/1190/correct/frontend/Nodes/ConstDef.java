package frontend.Nodes;

import frontend.Token;

public class ConstDef implements Node {
    private Token ident;
    private Token lBrack;
    private ConstExp constExp;
    private Token rBrack;
    private Token assign;
    private ConstInitVal constInitVal;

    public ConstDef() {
        this.ident = null;
        this.lBrack = null;
        this.constExp = null;
        this.rBrack = null;
        this.assign = null;
        this.constInitVal = null;
    }

    public void addIdent(Token ident) {
        this.ident = ident;
    }

    public void addLBrack(Token lBrack) {
        this.lBrack = lBrack;
    }

    public void addConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void addRBrack(Token rBrack) {
        this.rBrack = rBrack;
    }

    public void addAssign(Token assign) {
        this.assign = assign;
    }

    public void addConstInitVal(ConstInitVal constInitVal) {
        this.constInitVal = constInitVal;
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
        if (constExp != null) {
            sb.append(constExp.error());
        }
        if (rBrack != null) {
            sb.append(rBrack.error());
        }
        if (assign != null) {
            sb.append(assign.error());
        }
        if (constInitVal != null) {
            sb.append(constInitVal.error());
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
        if (constExp != null) {
            sb.append(constExp.toString());
        }
        if (rBrack != null) {
            sb.append(rBrack.toString());
        }
        if (assign != null) {
            sb.append(assign.toString());
        }
        if (constInitVal != null) {
            sb.append(constInitVal.toString());
        }
        sb.append("<ConstDef>\n");
        return sb.toString();
    }
}
