package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 12:49
 */
public class StmtNodeOfExp implements SyntaxNode{
    private Exp exp;  // may
    private Token semicn;  // ';'

    public StmtNodeOfExp(Exp exp, Token semicn) {
        this.exp = exp;
        this.semicn = semicn;
    }
    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        if(this.exp!=null){
            sb.append(this.exp.output());
        }
        sb.append(this.semicn.output());
        return sb.toString();
    }
}
