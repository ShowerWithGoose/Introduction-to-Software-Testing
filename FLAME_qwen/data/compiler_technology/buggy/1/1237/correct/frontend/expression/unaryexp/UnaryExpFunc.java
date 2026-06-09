package frontend.expression.unaryexp;

import frontend.Token;
import frontend.terminal.Ident;
import frontend.expression.FuncRParams;

public class UnaryExpFunc implements UnaryExpEle {
    private final Ident ident;
    private final FuncRParams funcRParams;
    private final Token leftParent;
    private final Token rightParent;

    public UnaryExpFunc(Ident ident, Token leftParent, Token rightParent) {
        this.ident = ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.funcRParams = null;
    }

    public UnaryExpFunc(Ident ident, FuncRParams funcRParams, Token leftParent, Token rightParent) {
        this.ident = ident;
        this.funcRParams = funcRParams;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        sb.append(leftParent.syntaxOutput());
        if (funcRParams != null) {
            sb.append(funcRParams.syntaxOutput());
        }
        sb.append(rightParent.syntaxOutput());
        return sb.toString();
    }
}
