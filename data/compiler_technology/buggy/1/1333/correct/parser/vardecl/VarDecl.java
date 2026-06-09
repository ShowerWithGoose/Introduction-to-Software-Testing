package parser.vardecl;

import lexer.Token;
import parser.Decl;
import parser.block.BlockItem;

import java.util.ArrayList;

public class VarDecl implements Decl, BlockItem {
    private final Token bType;
    private final ArrayList<VarDef> varDefs;

    public VarDecl(Token bType) {
        this.bType = bType;
        this.varDefs = new ArrayList<>();
    }

    public void addVarDef(VarDef varDef) {
        this.varDefs.add(varDef);
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append(this.bType.getType() + " " + this.bType.getName() + "\n");
        if (!this.varDefs.isEmpty()) {
            str.append(this.varDefs.get(0).toString());
            for (int i = 1; i < this.varDefs.size(); i++) {
                str.append("COMMA ,\n");
                str.append(this.varDefs.get(i).toString());
            }
        }
        str.append("SEMICN ;\n");
        str.append("<VarDecl>\n");
        return str.toString();
    }
}
