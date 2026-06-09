package Fronted.parser.syntax;

import Fronted.lexer.Token;

// UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
public class UnaryExp {

    private static final String name = "<UnaryExp>";

    private PrimaryExp primaryExp = null;

    private Token ident = null;

    private Token lparent = null;

    private FuncRParams funcRParams = null;

    private Token rparent = null;

    private UnaryOp unaryOp = null;

    private UnaryExp unaryExp = null;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public UnaryExp(Token ident, Token lparent, FuncRParams funcRParams, Token rparent) {
        this.ident = ident;
        this.lparent = lparent;
        this.funcRParams = funcRParams;
        this.rparent = rparent;
    }

    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        if (primaryExp!= null) {
            out.append(primaryExp);
        } else if (ident != null) {
            out.append(ident);
            out.append(lparent);
            if (funcRParams!= null) out.append(funcRParams);
            out.append(rparent);
        } else {
            out.append(unaryOp);
            out.append(unaryExp);
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public PrimaryExp getPrimaryExp() {
        return primaryExp;
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLparent() {
        return lparent;
    }

    public FuncRParams getFuncRParams() {
        return funcRParams;
    }

    public Token getRparent() {
        return rparent;
    }

    public UnaryOp getUnaryOp() {
        return unaryOp;
    }

    public UnaryExp getUnaryExp() {
        return unaryExp;
    }

    public void setPrimaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public void setIdent(Token ident) {
        this.ident = ident;
    }

    public void setLparent(Token lparent) {
        this.lparent = lparent;
    }

    public void setFuncRParams(FuncRParams funcRParams) {
        this.funcRParams = funcRParams;
    }

    public void setRparent(Token rparent) {
        this.rparent = rparent;
    }

    public void setUnaryOp(UnaryOp unaryOp) {
        this.unaryOp = unaryOp;
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }
}
