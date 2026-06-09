package frontend.parser.expr.types;

import frontend.lexer.Token;
import frontend.lexer.TokenType;

public class UnaryExp {
    private PrimaryExp primaryExp = null;
    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }
    private Token ident = null, lParent = null, rParent = null;
    private FuncRParams funcRParams = null;
    public static boolean isUnaryOp(Token token) {
        switch (token.getType()) {
            case PLUS, MINU, NOT -> {
                return true;
            }
            default -> {
                return false;
            }
        }
    }
    public UnaryExp(Token ident, Token lParent, FuncRParams funcRParams, Token rParent) {
        this.ident = ident;
        this.lParent = lParent;
        this.funcRParams = funcRParams;
        this.rParent = rParent;
    }
    public UnaryExp(Token ident, Token lParent, Token rParent) {
        this.ident = ident;
        this.lParent = lParent;
        this.rParent = rParent;
    }
    private Token unaryOp;
    private UnaryExp unaryExp;
    public UnaryExp(Token unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        if (primaryExp != null) {
            res.append(primaryExp);
        } else if (ident != null) {
            res.append(ident);
            res.append(lParent);
            if (funcRParams != null) {
                res.append(funcRParams);
            }
            res.append(rParent);
        } else {
            res.append(unaryOp);
            res.append("<UnaryOp>\n");
            res.append(unaryExp);
        }
        res.append("<UnaryExp>\n");
        return res.toString();
    }
}
