package frontend.Parser.Stmt;

import frontend.Token;

//| 'break' ';'
public class StmtBreak implements StmtInf{
    private Token breakTk;
    private Token semicn;

    public StmtBreak(Token breakTk, Token semicn) {
        this.breakTk = breakTk;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.breakTk.toString());
        sb.append(this.semicn.toString());
        return sb.toString();
    }
}
