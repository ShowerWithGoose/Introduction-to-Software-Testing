package syntacticanalysis.node.init;

import lexicalanalysis.Token;
import syntacticanalysis.node.expression.ConstExp;

public class ConstDef {
    private String name = "<ConstDef>";
    private Token ident;
    private Token lbrack;
    private ConstExp constExp;
    private Token rbrack;
    private Token assign;
    private ConstInitVal constInitVal;

    public ConstDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack, Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
        this.assign = assign;
        this.constInitVal = constInitVal;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        sb.append("\n");
        if (lbrack != null) {
            sb.append(lbrack);
            sb.append("\n");
            sb.append(constExp.syntaxOutput());
            sb.append("\n");
            sb.append(rbrack);
            sb.append("\n");
        }
        sb.append(assign);
        sb.append("\n");
        sb.append(constInitVal.syntaxOutput());
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
