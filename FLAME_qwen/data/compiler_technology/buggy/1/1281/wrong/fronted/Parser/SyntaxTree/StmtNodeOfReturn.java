package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

/**
 * @author
 * @Description:
 * @date 2024/10/13 13:41
 */
public class StmtNodeOfReturn implements SyntaxNode{
    private Token returnTk; // return\
    private Exp exp; //may
    private Token semicn; // ';'

    public StmtNodeOfReturn(Token returnTk, Exp exp, Token semicn) {
        this.returnTk = returnTk;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.returnTk.output());
        if(this.exp!=null){
            sb.append(this.exp.output());
        }
        sb.append(this.semicn.output());
        return sb.toString();
    }
}
