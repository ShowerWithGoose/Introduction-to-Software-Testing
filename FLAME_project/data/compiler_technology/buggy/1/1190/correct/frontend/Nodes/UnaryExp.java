package frontend.Nodes;

import frontend.Token;

public class UnaryExp implements Node {
    private int type;
    private PrimaryExp primaryExp;
    private Token ident;
    private Token lParent;
    private FuncRParams funcRParams;
    private Token rParent;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp() {
        this.type = 0;
        this.primaryExp = null;
        this.ident = null;
        this.lParent = null;
        this.funcRParams = null;
        this.rParent = null;
        this.unaryOp = null;
        this.unaryExp = null;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void addPrimaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public void addIdent(Token ident) {
        this.ident = ident;
    }

    public void addLParent(Token lParent) {
        this.lParent = lParent;
    }

    public void addFuncRParams(FuncRParams funcRParams) {
        this.funcRParams = funcRParams;
    }

    public void addRParent(Token rParent) {
        this.rParent = rParent;
    }

    public void addUnaryOp(UnaryOp unaryOp) {
        this.unaryOp = unaryOp;
    }

    public void addUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public PrimaryExp getPrimaryExp() {
        return primaryExp;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case 1:
                if (primaryExp != null) {
                    sb.append(primaryExp.error());
                }
                break;
            case 2:
                if (ident != null) {
                    sb.append(ident.error());
                }
                if (lParent != null) {
                    sb.append(lParent.error());
                }
                if (funcRParams != null) {
                    sb.append(funcRParams.error());
                }
                if (rParent != null) {
                    sb.append(rParent.error());
                }
                break;
            case 3:
                if (unaryOp != null) {
                    sb.append(unaryOp.error());
                }
                if (unaryExp != null) {
                    sb.append(unaryExp.error());
                }
                break;
            default:
                break;
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case 1:
                if (primaryExp != null) {
                    sb.append(primaryExp.toString());
                }
                break;
            case 2:
                if (ident != null) {
                    sb.append(ident.toString());
                }
                if (lParent != null) {
                    sb.append(lParent.toString());
                }
                if (funcRParams != null) {
                    sb.append(funcRParams.toString());
                }
                if (rParent != null) {
                    sb.append(rParent.toString());
                }
                break;
            case 3:
                if (unaryOp != null) {
                    sb.append(unaryOp.toString());
                }
                if (unaryExp != null) {
                    sb.append(unaryExp.toString());
                }
                break;
            default:
                break;
        }
        sb.append("<UnaryExp>\n");
        return sb.toString();
    }
}
