package frontend.parser.declaration;

import frontend.parser.SyntaxUnit;
import frontend.parser.block.BlockItemUnit;

public class Decl implements BlockItemUnit, SyntaxUnit {
    //Decl → ConstDecl | VarDecl
    private final String name = "<Decl>";
    private DeclUnit declUnit;

    public Decl(DeclUnit declUnit) {
        this.declUnit = declUnit;
    }

    @Override
    public String syntaxPrint() {
        //不输出名字
        StringBuilder sb = new StringBuilder();
        sb.append(this.declUnit.syntaxPrint());
        return sb.toString();
    }
}
