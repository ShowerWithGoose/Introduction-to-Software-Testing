package syntacticanalysis.node.init;

import lexicalanalysis.Token;
import syntacticanalysis.node.expression.ConstExp;

public class VarDef {
    private String name = "<VarDef>";
    private Token ident;
    private Token lbrack;
    private ConstExp constExp;
    private Token rbrack;
    private Token assign;
    private InitVal initVal;

    public VarDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack, Token assign, InitVal initVal) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
        this.assign = assign;
        this.initVal = initVal;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        if (lbrack != null) {
            sb.append("\n");
            sb.append(lbrack);
            sb.append("\n");
            sb.append(constExp.syntaxOutput());
            sb.append("\n");
            sb.append(rbrack);
        }
        if (assign != null) {
            sb.append("\n");
            sb.append(assign);
            sb.append("\n");
            sb.append(initVal.syntaxOutput());
        }
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
