package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 13:43
 */
public class StmtNodeOfGetint implements SyntaxNode{
    private LVal lVal;
    private Token equal;
    private Token getintTk;
    private Token leftParent; // '('
    private Token rightParent; // ')'
    private Token semicn; // ';'

    public StmtNodeOfGetint(LVal lVal, Token equal, Token getintTk, Token leftParent, Token rightParent, Token semicn) {
        this.lVal = lVal;
        this.equal = equal;
        this.getintTk = getintTk;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lVal.output());
        sb.append(this.equal.output());
        sb.append(this.getintTk.output());
        sb.append(this.leftParent.output());
        sb.append(this.rightParent.output());
        sb.append(this.semicn.output());
        return sb.toString();
    }
}
