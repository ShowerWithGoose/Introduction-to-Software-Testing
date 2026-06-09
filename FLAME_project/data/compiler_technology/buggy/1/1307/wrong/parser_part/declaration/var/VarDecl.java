package parser_part.declaration.var;

import lexer_part.Token;
import parser_part.declaration.BType;
import parser_part.declaration.DeclComponent;
import parser_part.declaration.Def;
import parser_part.declaration.var.varDef.VarDef;

import java.util.ArrayList;

public class VarDecl implements DeclComponent {
    private final BType bType;
    private final VarDef varDef;
    private final ArrayList<Token> commas;
    private final ArrayList<Def> varDefs;
    private final Token semicn;

    public VarDecl(BType bType, VarDef varDef, ArrayList<Token> commas,
                   ArrayList<Def> varDefs, Token semicn) {
        this.bType   = bType;
        this.varDef  = varDef;
        this.commas  = commas;
        this.varDefs = varDefs;
        this.semicn  = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(bType.toString());
        sb.append(varDef.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i));
            sb.append(varDefs.get(i));
        }
        sb.append(semicn.toString()).append("<VarDecl>\n");
        return sb.toString();
    }

    @Override
    public Def getFirstDef() {
        return varDef;
    }

    @Override
    public ArrayList<Def> getDefs() {
        return varDefs;
    }
}
