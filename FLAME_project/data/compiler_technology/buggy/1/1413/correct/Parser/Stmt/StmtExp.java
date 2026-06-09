package Parser.Stmt;

import Lexer.Token;
import Parser.Exp.Exp;

/**
 * 注意，这里Exp一定存在，将不存在的情况单独拆分为StmtNull
 * Stmt -> <Exp> ';'
 */
public class StmtExp implements StmtEle {
    private Exp exp;
    private Token semicn; // ';'

    public StmtExp(Exp exp, Token semicn) {
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.exp.print_tree());
        sb.append(this.semicn.toStringprint());
        return sb.toString();
    }
}
