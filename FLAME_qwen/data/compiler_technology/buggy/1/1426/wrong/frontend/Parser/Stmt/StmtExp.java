package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.Exp.Exp;

//| [Exp] ';' //有无Exp两种情况
public class StmtExp implements StmtInf{
    private Exp exp;
    private Token semicn;

    public StmtExp(Exp exp, Token semicn) {
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.Parser_Output());
        sb.append(semicn.toString());
        return sb.toString();
    }
}
