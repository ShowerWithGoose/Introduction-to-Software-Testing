package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

/**
 * PrimaryExpExp <PrimaryExp>Exp子节点类
 * '(' <Exp> ')'
 */
public class PrimaryExpExp implements PrimaryExpEle {
    /**
     * 属性：
     * leftParent '('
     * exp <Exp>
     * rightParent ')'
     */
    private Token leftParent;
    private Exp exp;
    private Token rightParent;

    public PrimaryExpExp(Token leftBracket, Exp exp, Token rightParent) {
        this.leftParent = leftBracket;
        this.exp = exp;
        this.rightParent = rightParent;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftParent.syntaxOutput());
        sb.append(exp.syntaxOutput());
        sb.append(rightParent.syntaxOutput());
        return sb.toString();
    }
}
