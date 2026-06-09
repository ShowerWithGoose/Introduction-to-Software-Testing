package syntacticanalysis.node.stmts;

import lexicalanalysis.Token;
import syntacticanalysis.node.LVal;
import syntacticanalysis.node.expression.Exp;

public class ForStmt {
    private String name = "<ForStmt>";
    private LVal lval;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lval, Token assign, Exp exp)
    {
        this.lval = lval;
        this.assign = assign;
        this.exp = exp;
    }

    public String syntaxOutput() {
        return lval.syntaxOutput() + "\n" + assign + "\n" + exp.syntaxOutput() + "\n" + name;
    }
}
