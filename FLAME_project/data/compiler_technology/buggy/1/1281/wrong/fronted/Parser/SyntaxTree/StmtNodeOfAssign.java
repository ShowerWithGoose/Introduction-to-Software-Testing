package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 12:47
 */
public class StmtNodeOfAssign implements SyntaxNode{
    private LVal lVal;
    private Token equal;  // '='
    private Exp exp;
    private Token semicn;  // ';'

    public StmtNodeOfAssign(LVal lVal, Token equal, Exp exp, Token semicn) {
        this.lVal = lVal;
        this.equal = equal;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lVal.output());
        sb.append(this.equal.output());
        sb.append(this.exp.output());
        sb.append(this.semicn.output());
        return sb.toString();
    }
}
