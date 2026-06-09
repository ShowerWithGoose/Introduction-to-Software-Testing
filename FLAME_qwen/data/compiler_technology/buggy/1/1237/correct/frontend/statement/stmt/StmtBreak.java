package frontend.statement.stmt;

import frontend.Token;

public class StmtBreak implements StmtEle {
    private Token breakTk; // 'break'
    private Token semicn; // ';'

    public StmtBreak(Token breakTk,
                     Token semicn) {
        this.breakTk = breakTk;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.breakTk.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}
