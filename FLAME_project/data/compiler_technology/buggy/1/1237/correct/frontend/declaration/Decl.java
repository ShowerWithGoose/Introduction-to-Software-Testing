package frontend.declaration;

import frontend.SyntaxNode;
import frontend.statement.blockitem.BlockItemEle;

/**
 * 声明类 Decl
 */
public class Decl implements BlockItemEle {
    private final SyntaxNode declEle;
    private final String name = "<Decl>";
    public Decl(SyntaxNode declEle) {
        if (declEle == null) {
            throw new IllegalArgumentException("SyntaxNode cannot be null");
        }
        this.declEle = declEle;
    }

    @Override
    public String syntaxOutput() {
        return declEle.syntaxOutput();
    }

    @Override
    public String toString() {
        return declEle.toString();
    }
}