package frontend.Parser.Stmt;

import frontend.Token;
import frontend.Parser.Exp.Exp;
import frontend.Parser.PriExp.LVal;

//语句 Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
public class StmtLvalExp implements StmtInf{
    private LVal lval;
    private Token equal;
    private Exp exp;
    private Token semicn;

    public StmtLvalExp(LVal lval,Token equal, Exp exp, Token semicn) {
        this.lval = lval;
        this.equal = equal;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(lval.Parser_Output());
        sb.append(equal.toString());
        sb.append(exp.Parser_Output());
        sb.append(semicn.toString());
        return sb.toString();
    }
}
