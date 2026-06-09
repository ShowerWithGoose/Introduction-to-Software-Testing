package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;
import syntacticanalysis.node.expression.Exp;

public class Stmt7 extends Stmt {
    private String name = "<Stmt>";
    private Token returnTk;
    private Exp exp;
    private Token semicn;

    public Stmt7(Token returnTk, Exp exp, Token semicn) {
        this.returnTk = returnTk;
        this.exp = exp;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(returnTk);
        sb.append("\n");
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
