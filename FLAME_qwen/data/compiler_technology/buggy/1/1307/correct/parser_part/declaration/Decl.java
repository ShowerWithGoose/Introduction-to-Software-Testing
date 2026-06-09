package parser_part.declaration;

import llvm_part.IrValue;
import parser_part.block.BlockItemComponent;
import parser_part.declaration.constance.ConstDecl;
import parser_part.declaration.var.VarDecl;

public class Decl implements BlockItemComponent {
    private DeclComponent declComponent;

    public Decl(DeclComponent declComponent) {
        this.declComponent = declComponent;
    }

    @Override
    public String toString() {
        return declComponent.toString();
    }

    public DeclComponent getDeclComponent() {
        return declComponent;
    }
}
