package syntacticanalysis.node.expression;

import lexicalanalysis.Token;

public class PrimaryExp1 extends PrimaryExp {
    private String name = "<PrimaryExp>";
    private Token lparent;
    private Exp exp;
    private Token rparent;

    public PrimaryExp1(Token lparent, Exp exp, Token rparent)
    {
        this.lparent = lparent;
        this.exp = exp;
        this.rparent = rparent;
    }

    @Override
    public String syntaxOutput() {
        return lparent + "\n" + exp.syntaxOutput() + "\n" + rparent + "\n" + name;
    }
}
