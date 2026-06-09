package frontend.parser.ast.decl;

import frontend.parser.ast.block.BItem;

public class Decl implements BItem { 
    private String type = "<Decl>";
    private Declaration declaration;

    public Decl(Declaration declaration) {
        this.declaration = declaration;
    }

    public String getOutput() {
        return declaration.getOutput();
    }

    public String getError() {
        return declaration.getError();
    }
    
}
