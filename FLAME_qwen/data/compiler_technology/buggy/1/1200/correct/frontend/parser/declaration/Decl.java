package frontend.parser.declaration;

import frontend.parser.block.BItem;

public class Decl implements BItem {
    private final String name = "<Decl>";
    private Declaration declaration;

    public Decl(Declaration declaration) {
        this.declaration = declaration;
    }

    public String getOutPut() {
        return declaration.getOutPut();
    }

    public String getError() {
        return declaration.getError();
    }
}
