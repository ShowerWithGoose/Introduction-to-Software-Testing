package syntaxTree;

import token.TokenType;

import java.util.ArrayList;

public class ConstDecl extends Decl {
    final ArrayList<ConstDef> constDefs;

    public ConstDecl(TokenType bType, ArrayList<ConstDef> constDefs) {
        super(bType);
        this.constDefs = constDefs;
    }
}
