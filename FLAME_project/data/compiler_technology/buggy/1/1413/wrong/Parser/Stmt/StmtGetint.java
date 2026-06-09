package Parser.Stmt;

import Lexer.Token;
import Parser.LVal;

public class StmtGetint implements StmtEle {
    private LVal lval;
    private Token eq; // '='
    private Token getint; // 'getint'
    private Token leftParent; // '('
    private Token rightParent; // ')'
    private Token semicn; // ';'

    public StmtGetint(LVal lval,
                      Token eq,
                      Token getint,
                      Token leftParent,
                      Token rightParent,
                      Token semicn) {
        this.lval = lval;
        this.eq = eq;
        this.getint = getint;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String print_tree() {
        return this.lval.print_tree() +
                this.eq.toStringprint() +
                this.getint.toStringprint() +
                this.leftParent.toStringprint() +
                this.rightParent.toStringprint() +
                this.semicn.toStringprint();
    }
}
