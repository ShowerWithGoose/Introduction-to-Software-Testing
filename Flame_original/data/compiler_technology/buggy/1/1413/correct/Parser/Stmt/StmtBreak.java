package Parser.Stmt;

import Lexer.Token;

public class StmtBreak implements StmtEle {
    private Token breakTk; // 'break'
    private Token semicn; // ';'

    public StmtBreak(Token breakTk,
                     Token semicn) {
        this.breakTk = breakTk;
        this.semicn = semicn;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(breakTk.toStringprint());
        sb.append(semicn.toStringprint());
        return sb.toString();
    }
}
