package Parser.Stmt;


import Lexer.Token;

/**
 * 仅有分号
 * Stmt -> ';'
 */
public class StmtNull implements StmtEle {
    private Token semicn;

    public StmtNull(Token semicn) {
        this.semicn = semicn;
    }

    @Override
    public String print_tree() {
        return this.semicn.toStringprint();
    }
}
