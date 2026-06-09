package struct;

import token.Token;

/* UnaryExp â†’ PrimaryExp
* | Ident '(' [FuncRParams] ')'
* | UnaryOp UnaryExp
*/
public class UnaryExp {
    private PrimaryExp primaryExp;
    private Token ident;
    private Token lParentToken;
    private Token rParentToken;
    private FuncRParams funcRParams;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public UnaryExp(Token ident, Token lParentToken, FuncRParams funcRParams, Token rParentToken) {
        this.ident = ident;
        this.lParentToken = lParentToken;
        this.funcRParams = funcRParams;
        this.rParentToken = rParentToken;
    }

    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    public PrimaryExp getPrimaryExp() {
        return primaryExp;
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLParentToken() {
        return lParentToken;
    }

    public Token getRParentToken() {
        return rParentToken;
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
        StringBuilder sb = new StringBuilder();
        if (primaryExp != null) {
            sb.append(primaryExp.toString());
        } else if (ident != null) {
            sb.append(ident.toString());
            sb.append(lParentToken.toString());
            if (funcRParams != null) {
                sb.append(funcRParams.toString());
            }
            sb.append(rParentToken.toString());
        } else {
            sb.append(unaryOp.toString());
            sb.append(unaryExp.toString());
        }
        sb.append("<UnaryExp>\n");
        return sb.toString();
    }
}
