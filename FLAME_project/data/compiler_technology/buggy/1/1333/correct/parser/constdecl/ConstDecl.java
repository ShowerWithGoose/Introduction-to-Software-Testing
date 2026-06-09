package parser.constdecl;

import lexer.Token;
import parser.Decl;
import parser.block.BlockItem;

import java.util.ArrayList;

public class ConstDecl implements Decl, BlockItem {
    private final Token bType;
    private final ArrayList<ConstDef> constDefs;

    public ConstDecl(Token bType) {
        this.bType = bType;
        this.constDefs = new ArrayList<>();
    }

    public void addConstDef(ConstDef constDef) {
        this.constDefs.add(constDef);
    }

    public String toString() {
        StringBuilder str = new StringBuilder("CONSTTK const\n");
        str.append(this.bType.getType() + " " + this.bType.getName() + "\n");
        if (!this.constDefs.isEmpty()) {
            str.append(this.constDefs.get(0).toString());
            for (int i = 1; i < this.constDefs.size(); i++) {
                str.append("COMMA ,\n");
                str.append(this.constDefs.get(i).toString());
            }
        }
        str.append("SEMICN ;\n");
        str.append("<ConstDecl>\n");
        return str.toString();
    }
}
