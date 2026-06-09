package frontend.declaration.constant;

import frontend.Token;
import frontend.declaration.BType;
import frontend.declaration.DeclEle;

import java.util.List;

/**
 * 常量声明 ConstDecl
 */
public class ConstDecl implements DeclEle {
    private final String name = "<ConstDecl>";
    private final Token constTk; // 'const'
    private final BType btype;
    private final ConstDef first;
    private final List<Token> commas; // commas
    private final List<ConstDef> constDefs; // constDefs
    private final Token semicn; // ';'

    public ConstDecl(Token constTk, BType btype, ConstDef first, List<Token> commas, List<ConstDef> constDefs, Token semicn) {
        if (constTk == null || btype == null || first == null || semicn == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }
        if (commas != null && constDefs != null && commas.size() != constDefs.size()) {
            throw new IllegalArgumentException("Commas and constDefs must have the same size");
        }
        this.constTk = constTk;
        this.btype = btype;
        this.first = first;
        this.commas = commas;
        this.constDefs = constDefs;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(constTk.syntaxOutput());
        sb.append(btype.syntaxOutput());
        sb.append(first.syntaxOutput());
        if (commas != null && constDefs != null) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).syntaxOutput());
                sb.append(constDefs.get(i).syntaxOutput());
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