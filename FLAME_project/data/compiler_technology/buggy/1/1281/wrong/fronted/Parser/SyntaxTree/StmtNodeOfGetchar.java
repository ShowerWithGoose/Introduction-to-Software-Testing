package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 13:46
 */
public class StmtNodeOfGetchar implements SyntaxNode{
    private LVal lVal;
    private Token equal;
    private Token getcharTk;
    private Token leftParent; // '('
    private Token rightParent; // ')'
    private Token semicn; // ';'

    public StmtNodeOfGetchar(LVal lVal, Token equal, Token getcharTk, Token leftParent, Token rightParent, Token semicn) {
        this.lVal = lVal;
        this.equal = equal;
        this.getcharTk = getcharTk;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lVal.output());
        sb.append(this.equal.output());
        sb.append(this.getcharTk.output());
        sb.append(this.leftParent.output());
        sb.append(this.rightParent.output());
        sb.append(this.semicn.output());
        return sb.toString();
    }
}
