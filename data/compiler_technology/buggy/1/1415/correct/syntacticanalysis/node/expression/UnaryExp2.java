package syntacticanalysis.node.expression;

import lexicalanalysis.Token;
import syntacticanalysis.node.function.FuncRParams;

public class UnaryExp2 extends UnaryExp {
    private String name = "<UnaryExp>";
    private final Token ident;
    private final Token lparent;
    private final FuncRParams funcRParams;
    private final Token rparent;

    public UnaryExp2(Token ident, Token lparent, FuncRParams funcRParams, Token rparent)
    {
        this.ident = ident;
        this.lparent = lparent;
        this.funcRParams = funcRParams;
        this.rparent = rparent;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        sb.append("\n");
        sb.append(lparent);
        sb.append("\n");
        if (funcRParams != null) {
            sb.append(funcRParams.syntaxOutput());
            sb.append("\n");
        }
        sb.append(rparent);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
