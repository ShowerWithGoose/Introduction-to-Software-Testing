package syntacticanalysis.node.init;

import lexicalanalysis.Token;

import java.util.ArrayList;

public class VarDecl implements Decl {
    private String name = "<VarDecl>";
    private Token btype;
    private ArrayList<VarDef> varDefs;
    private Token semiCn;

    public VarDecl(Token btype, ArrayList<VarDef> varDefs, Token semiCn) {
        this.btype = btype;
        this.varDefs = varDefs;
        this.semiCn = semiCn;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(btype);
        sb.append("\n");
        sb.append(varDefs.get(0).syntaxOutput());
        if (varDefs.size() > 1) {
            for (int i = 1; i < varDefs.size(); i++) {
                sb.append("\n");
                sb.append("COMMA ,\n");
                sb.append(varDefs.get(i).syntaxOutput());
            }
        }
        sb.append("\n");
        sb.append(semiCn);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
