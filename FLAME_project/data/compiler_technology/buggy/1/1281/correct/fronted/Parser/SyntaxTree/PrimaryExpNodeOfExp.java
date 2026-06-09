package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/12 21:25
 */
public class PrimaryExpNodeOfExp implements SyntaxNode{
    private Token leftParent; // '('
    private Exp exp;
    private Token rightParent; // ')'

    public PrimaryExpNodeOfExp(Token leftParent, Exp exp, Token rightParent) {
        this.leftParent = leftParent;
        this.exp = exp;
        this.rightParent = rightParent;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftParent.output());
        sb.append(this.exp.output());
        sb.append(this.rightParent.output());
        return sb.toString();
    }
}
