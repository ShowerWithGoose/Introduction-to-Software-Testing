package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;

public class Stmt5 extends Stmt {
    private String name = "<Stmt>";
    private Token fortk;
    private Token lparent;
    private ForStmt forStmt1;
    private Token semicn1;
    private Cond cond;
    private Token semicn2;
    private ForStmt forStmt2;
    private Token rparent;
    private Stmt stmt;

    public Stmt5(Token fortk, Token lparent, ForStmt forStmt1,
                 Token semicn1, Cond cond, Token semicn2,
                 ForStmt forStmt2, Token rparent, Stmt stmt)
    {
        this.fortk = fortk;
        this.lparent = lparent;
        this.forStmt1 = forStmt1;
        this.semicn1 = semicn1;
        this.cond = cond;
        this.semicn2 = semicn2;
        this.forStmt2 = forStmt2;
        this.rparent = rparent;
        this.stmt = stmt;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(fortk);
        sb.append("\n");
        sb.append(lparent);
        sb.append("\n");
        if (forStmt1 != null) {
            sb.append(forStmt1.syntaxOutput());
            sb.append("\n");
        }
        sb.append(semicn1);
        sb.append("\n");
        if (cond != null) {
            sb.append(cond.syntaxOutput());
            sb.append("\n");
        }
        sb.append(semicn2);
        sb.append("\n");
        if (forStmt2 != null) {
            sb.append(forStmt2.syntaxOutput());
            sb.append("\n");
        }
        sb.append(rparent);
        sb.append("\n");
        sb.append(stmt.syntaxOutput());
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
