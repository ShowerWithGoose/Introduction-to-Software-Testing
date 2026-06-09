package syntaxTree;

import token.TokenType;

import java.util.ArrayList;

public class VarDecl extends Decl {
    final ArrayList<VarDef> constDefs;

    public VarDecl(TokenType bType, ArrayList<VarDef> constDefs) {
        super(bType);
        this.constDefs = constDefs;
    }
}
