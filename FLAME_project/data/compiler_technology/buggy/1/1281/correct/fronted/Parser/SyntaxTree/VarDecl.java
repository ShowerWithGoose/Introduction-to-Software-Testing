package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 1:28
 */
public class VarDecl implements SyntaxNode{
    private final String name = "<VarDecl>";
    private BType btype;
    private VarDef necVarDef;
    private ArrayList<Token> commas; // commas
    private ArrayList<VarDef> varDefs; // varDefs
    private Token semicn; // ';'

    public VarDecl(BType btype, VarDef necVarDef, ArrayList<Token> commas, ArrayList<VarDef> varDefs, Token semicn) {
        this.btype = btype;
        this.necVarDef = necVarDef;
        this.commas = commas;
        this.varDefs = varDefs;
        this.semicn = semicn;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.output());
        sb.append(this.necVarDef.output());
        if (!this.commas.isEmpty() && !varDefs.isEmpty() && this.commas.size() == this.varDefs.size()) {
            int len = this.commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).output());
                sb.append(this.varDefs.get(i).output());
            }
        }
        sb.append(this.semicn.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
