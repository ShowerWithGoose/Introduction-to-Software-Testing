package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;
import syntacticanalysis.node.expression.Exp;

public class Stmt2 extends Stmt {
    private String name = "<Stmt>";
    private Exp exp;
    private Token semicn;

    public Stmt2(Exp exp, Token semicn)
    {
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.syntaxOutput());
            sb.append("\n");
        }
        sb.append(semicn);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
