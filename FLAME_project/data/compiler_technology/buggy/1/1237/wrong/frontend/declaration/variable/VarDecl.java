package frontend.declaration.variable;

import frontend.Token;
import frontend.declaration.BType;
import frontend.declaration.DeclEle;
import frontend.declaration.variable.vardef.VarDef;
import java.util.List;

/**
 * 变量声明 VarDecl
 */
public class VarDecl implements DeclEle {
    private final String name = "<VarDecl>";
    private final BType btype;
    private final VarDef first;
    private final List<Token> commas; // ','
    private final List<VarDef> varDefs;
    private final Token semicn; // ';'

    public VarDecl(BType btype, VarDef first, List<Token> commas, List<VarDef> varDefs, Token semicn) {
        if (btype == null || first == null || semicn == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }
        if ((commas != null && varDefs != null) && (commas.size() != varDefs.size())) {
            throw new IllegalArgumentException("Commas and varDefs must have the same size");
        }
        this.btype = btype;
        this.first = first;
        this.commas = commas;
        this.varDefs = varDefs;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(btype.syntaxOutput());
        sb.append(first.syntaxOutput());
        if (commas != null && varDefs != null) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).syntaxOutput());
                sb.append(varDefs.get(i).syntaxOutput());
            }
        }
        sb.append(semicn.syntaxOutput());
        sb.append(name).append("\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}