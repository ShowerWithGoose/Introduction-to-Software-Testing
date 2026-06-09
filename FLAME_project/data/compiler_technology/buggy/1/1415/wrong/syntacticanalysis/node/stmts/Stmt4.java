package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;

public class Stmt4 extends Stmt {
    private String name = "<Stmt>";
    private Token ifTk;
    private Token lparent;
    private Cond cond;
    private Token rparent;
    private Stmt stmt1;
    private Token elseTk;
    private Stmt stmt2;

    public Stmt4(Token ifTk, Token lparent, Cond cond, Token rparent, Stmt stmt1,
                 Token elseTk, Stmt stmt2)
    {
        this.ifTk = ifTk;
        this.lparent = lparent;
        this.cond = cond;
        this.rparent = rparent;
        this.stmt1 = stmt1;
        this.elseTk = elseTk;
        this.stmt2 = stmt2;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ifTk);
        sb.append("\n");
        sb.append(lparent);
        sb.append("\n");
        sb.append(cond.syntaxOutput());
        sb.append("\n");
        sb.append(rparent);
        sb.append("\n");
        sb.append(stmt1.syntaxOutput());
        sb.append("\n");
        if (elseTk != null) {
            sb.append(elseTk);
            sb.append("\n");
            sb.append(stmt2.syntaxOutput());
            sb.append("\n");
        }
        sb.append(name);
        return sb.toString();
    }
}
