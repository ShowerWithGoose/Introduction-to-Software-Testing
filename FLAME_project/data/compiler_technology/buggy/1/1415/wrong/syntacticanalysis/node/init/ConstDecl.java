package syntacticanalysis.node.init;

import lexicalanalysis.Token;

import java.util.ArrayList;

public class ConstDecl implements Decl {
    private String name = "<ConstDecl>";
    private Token constTk;  //const
    private Token btype;  //BType
    private ArrayList<ConstDef> constDefs;
    private Token semiCn;

    public ConstDecl(Token constTk, Token btype, ArrayList<ConstDef> constDefs, Token semiCn) {
        this.constTk = constTk;
        this.btype = btype;
        this.constDefs = constDefs;
        this.semiCn = semiCn;
    }

    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(constTk);
        sb.append("\n");
        sb.append(btype);
        if (!constDefs.isEmpty()) {
            sb.append("\n");
            sb.append(constDefs.get(0).syntaxOutput());
            if (constDefs.size() > 1) {
                for (int i = 1; i < constDefs.size(); i++) {
                    sb.append("\n");
                    sb.append("COMMA ,\n");
                    sb.append(constDefs.get(i).syntaxOutput());
                }
            }
        }
        sb.append("\n");
        sb.append(semiCn);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }

}
