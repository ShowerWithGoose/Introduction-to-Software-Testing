package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import java.util.ArrayList;
/*
VarDecl â†’ BType VarDef { ',' VarDef } ';'// i
 */
public class VarDecl extends Decl {
    private final String name = "<VarDecl>";
    private BType bType;
    private VarDef firstVarDef;
    private ArrayList<VarDef> varDefs;
    private ArrayList<Token> commas;
    private Token semicn;

    public VarDecl(BType bType, VarDef firstVarDef, ArrayList<VarDef> varDefs, ArrayList<Token> commas, Token semicn) {
        this.bType = bType;
        this.firstVarDef = firstVarDef;
        this.semicn = semicn;
        this.varDefs = varDefs;
        this.commas = commas;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType);
        sb.append(firstVarDef);
        for (int i = 0; i < varDefs.size(); i++) {
            sb.append(commas.get(i));
            sb.append(varDefs.get(i));
        }
        sb.append(semicn);
        sb.append(name + "\n");
        return sb.toString();
    }
}
