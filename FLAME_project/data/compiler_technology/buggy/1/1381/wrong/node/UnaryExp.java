package node;

import frontend.Parser;

public class UnaryExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.UnaryExp;
    private PrimaryExp primaryExp;
    private Ident ident;
    private FuncRParams funcRParams;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
        this.ident = null;
        this.funcRParams = null;
        this.unaryOp = null;
        this.unaryExp = null;
    }

    public UnaryExp(Ident ident) {
        this.ident = ident;
        this.primaryExp = null;
        this.funcRParams = null;
        this.unaryOp = null;
        this.unaryExp = null;
    }

    public UnaryExp(Ident ident, FuncRParams funcRParams) {
        this.ident = ident;
        this.funcRParams = funcRParams;
        this.primaryExp = null;
        this.unaryOp = null;
        this.unaryExp = null;
    }

    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
        this.primaryExp = null;
        this.ident = null;
        this.funcRParams = null;
    }

    public PrimaryExp getPrimaryExp() {
        return primaryExp;
    }

    public Ident getIdent() {
        return ident;
    }

    public FuncRParams getFuncRParams() {
        return funcRParams;
    }

    public UnaryOp getUnaryOp() {
        return unaryOp;
    }

    public UnaryExp getUnaryExp() {
        return unaryExp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (primaryExp != null)
            ret.append("\n").append(primaryExp);
        else if (ident != null)
            ret.append("\n").append(ident).append("\n").append(funcRParams);
        else
            ret.append("\n").append(unaryOp).append("\n").append(unaryExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
