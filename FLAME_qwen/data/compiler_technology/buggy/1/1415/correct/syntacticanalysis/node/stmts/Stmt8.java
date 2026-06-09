package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;
import syntacticanalysis.node.LVal;

public class Stmt8 extends Stmt {
    private String name = "<Stmt>";
    private LVal lval;
    private Token assign;
    private Token getIntTk;
    private Token lparent;
    private Token rparent;
    private Token semicn;

    public Stmt8(LVal lval, Token assign, Token getIntTk, Token lparent, Token rparent, Token semicn) {
        this.lval = lval;
        this.assign = assign;
        this.getIntTk = getIntTk;
        this.lparent = lparent;
        this.rparent = rparent;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lval.syntaxOutput());
        sb.append("\n");
        sb.append(assign);
        sb.append("\n");
        sb.append(getIntTk);
        sb.append("\n");
        sb.append(lparent);
        sb.append("\n");
        sb.append(rparent);
        sb.append("\n");
        sb.append(semicn);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
