package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.Exp.Exp;

//| 'return' [Exp] ';' // 1.有Exp 2.无Exp
public class StmtReturn implements StmtInf{
    private Token returnTk;
    private Exp exp;
    private Token semicn;

    public StmtReturn(Token returnTk, Token semicn) {
        this.returnTk = returnTk;
        this.semicn = semicn;
    }
    public StmtReturn(Token returnTk, Exp exp, Token semicn) {
        this.returnTk = returnTk;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.returnTk.toString());
        if(exp != null){
            sb.append(exp.Parser_Output());
        }
        sb.append(this.semicn.toString());
        return sb.toString();
    }
}
