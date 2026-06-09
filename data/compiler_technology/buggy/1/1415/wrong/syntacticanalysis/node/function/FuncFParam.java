package syntacticanalysis.node.function;

import lexicalanalysis.Token;

public class FuncFParam {
    private String name = "<FuncFParam>";
    private Token btype;
    private Token ident;
    private Token lbrack;
    private Token rbrack;

    public FuncFParam(Token btype, Token ident, Token lbrack, Token rbrack)
    {
        this.btype = btype;
        this.ident = ident;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(btype);
        sb.append("\n");
        sb.append(ident);
        if (lbrack != null) {
            sb.append("\n");
            sb.append(lbrack);
            sb.append("\n");
            sb.append(rbrack);
        }
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
