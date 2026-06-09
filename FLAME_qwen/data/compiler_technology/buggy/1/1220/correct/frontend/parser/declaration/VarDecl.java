package frontend.parser.declaration;

import frontend.lexer.Token;

import java.util.ArrayList;

public class VarDecl implements DeclUnit{
    //VarDecl â†’ BType VarDef { ',' VarDef } ';' /
    private final String name = "<VarDecl>";
    private BType bType;
    private VarDef firstVarDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> varDefs;
    private Token semicn; //;

    public VarDecl(BType bType, VarDef firstVarDef, ArrayList<Token> commas,
                   ArrayList<VarDef> varDefs, Token semicn) {
        this.bType = bType;
        this.firstVarDef = firstVarDef;
        this.commas = commas;
        this.varDefs = varDefs;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.bType.syntaxPrint());
        sb.append(this.firstVarDef.syntaxPrint());
        if (commas != null && !commas.isEmpty()
        && varDefs != null && !varDefs.isEmpty()) {
            int len = commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(commas.get(i).syntaxPrint());
                sb.append(varDefs.get(i).syntaxPrint());
            }
        }
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
