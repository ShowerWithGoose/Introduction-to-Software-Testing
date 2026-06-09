package Parser.Stmt;

import Lexer.Token;
import Parser.Exp.Exp;
import Parser.LVal;

/**
 * Stmt -> <LVal> '=' <Exp> ';'
 */
public class StmtAssign implements StmtEle {
    private LVal lval;
    private Token eq; // '='
    private Exp exp;
    private Token semicn; // ';'

    public StmtAssign(LVal lval,
                      Token eq,
                      Exp exp,
                      Token semicn) {
        this.lval = lval;
        this.eq = eq;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lval.print_tree());
        sb.append(this.eq.toStringprint());
        sb.append(this.exp.print_tree());
        sb.append(this.semicn.toStringprint());
        return sb.toString();
    }

}
