package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;
import syntacticanalysis.node.LVal;
import syntacticanalysis.node.expression.Exp;

public class Stmt1 extends Stmt {
    private String name = "<Stmt>";
    private LVal lval;
    private Token assign;
    private Exp exp;
    private Token semicn;

    public Stmt1(LVal lval, Token assign, Exp exp, Token semicn)
    {
        this.lval = lval;
        this.assign = assign;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(lval.syntaxOutput());
        sb.append("\n");
        sb.append(assign);
        sb.append("\n");
        sb.append(exp.syntaxOutput());
        sb.append("\n");
        sb.append(semicn);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
