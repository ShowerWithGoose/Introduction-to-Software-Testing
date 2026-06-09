package Parser.Stmt;

import Lexer.Token;

public class StmtContinue implements StmtEle {
    private Token continueTk; // 'continue'
    private Token semicn; // ';'

    public StmtContinue(Token continueTk,
                        Token semicn) {
        this.continueTk = continueTk;
        this.semicn = semicn;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(continueTk.toStringprint());
        sb.append(semicn.toStringprint());
        return sb.toString();
    }
}
