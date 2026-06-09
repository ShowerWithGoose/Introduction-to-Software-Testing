package frontend.Parser.Stmt;

import frontend.Token;

//| 'continue' ';'
public class StmtContinue implements StmtInf{
    private Token continueTk;
    private Token semicn;

    public StmtContinue(Token continueTk, Token semicn) {
        this.continueTk = continueTk;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.continueTk.toString());
        sb.append(this.semicn.toString());
        return sb.toString();
    }
}
