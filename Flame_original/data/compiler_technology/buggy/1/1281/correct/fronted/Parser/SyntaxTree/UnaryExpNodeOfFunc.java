package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/12 23:22
 */
public class UnaryExpNodeOfFunc implements SyntaxNode{
    private Token ident;
    private Token leftParent; // '('
    private FuncRParams funcRParams; // may
    private Token rightParent; // ')'

    public UnaryExpNodeOfFunc(Token ident, Token leftParent, FuncRParams funcRParams, Token rightParent) {
        this.ident = ident;
        this.leftParent = leftParent;
        this.funcRParams = funcRParams;
        this.rightParent = rightParent;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.output());
        sb.append(this.leftParent.output());
        if (this.funcRParams != null) {
            sb.append(this.funcRParams.output());
        }
        sb.append(this.rightParent.output());
        return sb.toString();
    }
}
