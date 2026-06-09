package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;

public class Stmt6 extends Stmt {
    private String name = "<Stmt>";
    private Token breakcontinuetk;
    private Token semicn;

    public Stmt6(Token breakcontinuetk, Token semicn) {
        this.breakcontinuetk = breakcontinuetk;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        return breakcontinuetk + "\n" + semicn + "\n" + name;
    }
}
