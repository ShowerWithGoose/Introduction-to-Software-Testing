package frontend.Nodes;

import frontend.Token;

public class VarDef implements Node {
    private int type;

    private Token ident;
    private Token lBrack;
    private ConstExp constExp;
    private Token rBrack;
    private Token assign;
    private InitVal initVal;

    public VarDef() {
        this.type = 0;
        this.ident = null;
        this.lBrack = null;
        this.constExp = null;
        this.rBrack = null;
        this.assign = null;
        this.initVal = null;
    }

    public void setType(int type) {
        this.type = type;
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

    public void addInitVal(InitVal initVal) {
        this.initVal = initVal;
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
        if (initVal != null) {
            sb.append(initVal.error());
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
        if (initVal != null) {
            sb.append(initVal.toString());
        }
        sb.append("<VarDef>\n");
        return sb.toString();
    }
}
