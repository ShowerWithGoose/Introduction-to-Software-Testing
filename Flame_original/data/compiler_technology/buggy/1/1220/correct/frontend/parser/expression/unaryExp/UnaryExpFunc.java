package frontend.parser.expression.unaryExp;

import frontend.lexer.Token;

public class UnaryExpFunc implements UnaryExpUnit{
    //Ident '(' [FuncRParams] ')'
    private Token ident;
    private Token leftParent;
    private Token rightParent;
    private FuncRParams funcRParams;
    public UnaryExpFunc(Token ident, Token leftParent, Token rightParent, FuncRParams funcRParams) {
        this.ident = ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.funcRParams = funcRParams;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxPrint());
        sb.append(leftParent.syntaxPrint());
        if (funcRParams != null) {
            sb.append(funcRParams.syntaxPrint());
        }
        if (rightParent != null) {
            sb.append(rightParent.syntaxPrint());
        }
        return sb.toString();
    }
}
