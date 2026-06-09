package frontend.GrammaticalElements.expression;

import frontend.GrammaticalElements.function.FuncFParams;
import frontend.GrammaticalElements.UnaryOp;
import frontend.GrammaticalElements.function.FuncRParams;
import frontend.Token;

public class UnaryExp {
    private final String name = "<UnaryExp>";
    private PrimaryExp primaryExp;
    private Token ident;
    private Token leftParen;
    private FuncRParams funcRParams;
    private Token rightParen;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public UnaryExp(Token ident, Token leftParen, FuncRParams funcRParams, Token rightParen) {
        this.ident = ident;
        this.leftParen = leftParen;
        this.funcRParams = funcRParams;
        this.rightParen = rightParen;
    }

    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    public UnaryExp(Token ident, Token leftParen, Token rightParen) {
        this.ident = ident;
        this.leftParen = leftParen;
        this.rightParen = rightParen;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (primaryExp != null) {
            sb.append(primaryExp.toString());
        } else if (ident != null && leftParen != null && funcRParams != null && rightParen != null) {
            sb.append(ident.toString());
            sb.append(leftParen.toString());
            sb.append(funcRParams.toString());
            sb.append(rightParen.toString());
        } else if (unaryOp != null && unaryExp != null) {
            sb.append(unaryOp.toString());
            sb.append(unaryExp.toString());
        } else {
            sb.append(ident.toString());
            sb.append(leftParen.toString());
            sb.append(rightParen.toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }

}
