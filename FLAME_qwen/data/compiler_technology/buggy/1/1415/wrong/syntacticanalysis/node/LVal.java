package syntacticanalysis.node;

import lexicalanalysis.Token;
import syntacticanalysis.node.expression.Exp;

public class LVal {
    private String name = "<LVal>";
    private Token ident;
    private Token lbrack;
    private Exp exp;
    private Token rbrack;

    public LVal(Token ident, Token lbrack, Exp exp, Token rbrack)
    {
        this.ident = ident;
        this.lbrack = lbrack;
        this.exp = exp;
        this.rbrack = rbrack;
    }

    public String syntaxOutput()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        if (lbrack != null) {
            sb.append("\n");
            sb.append(lbrack);
            sb.append("\n");
            sb.append(exp.syntaxOutput());
            sb.append("\n");
            sb.append(rbrack);
        }
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
