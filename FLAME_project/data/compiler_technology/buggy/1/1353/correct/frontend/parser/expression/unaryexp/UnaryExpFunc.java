package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.parser.expression.FuncRParams;
import frontend.parser.terminal.Ident;

/**
 * UnaryExpFunc <UnaryExp>Func子节点类
 * <Ident> '(' [<FuncRParams>] ')'
 */
public class UnaryExpFunc implements UnaryExpEle {
    /**
     * 属性：
     * ident <Ident>
     * leftParent '('
     * funcRParams <FuncRParams>，可选
     * rightParent ')'
     */
    private Ident ident;
    private FuncRParams funcRParams = null;
    private Token leftParent;
    private Token rightParent;

    public UnaryExpFunc(Ident ident,
                        Token leftParent,
                        Token rightParent) {
        this.ident = ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
    }

    public UnaryExpFunc(Ident ident,
                        FuncRParams funcRParams,
                        Token leftParent,
                        Token rightBracker) {
        this(ident, leftParent, rightBracker);
        this.funcRParams = funcRParams;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        sb.append(leftParent.syntaxOutput());
        if (funcRParams != null) {
            sb.append(this.funcRParams.syntaxOutput());
        }
        sb.append(rightParent.syntaxOutput());
        return sb.toString();
    }
}
