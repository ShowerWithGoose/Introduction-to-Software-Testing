package Parser.Stmt;

import Lexer.Token;
import Parser.LVal;

/**
 * @Description:
 * @date 2024/10/13
 */
public class StmtGetchar implements StmtEle{
    private LVal lval;
    private Token eq; // '='
    private Token getchar; // 'getint'
    private Token leftParent; // '('
    private Token rightParent; // ')'
    private Token semicn; // ';'

    public StmtGetchar(LVal lval, Token eq, Token getchar, Token leftParent, Token rightParent, Token semicn) {
        this.lval = lval;
        this.eq = eq;
        this.getchar = getchar;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String print_tree() {
        return this.lval.print_tree() +
                this.eq.toStringprint() +
                this.getchar.toStringprint() +
                this.leftParent.toStringprint() +
                this.rightParent.toStringprint() +
                this.semicn.toStringprint();
    }
}
