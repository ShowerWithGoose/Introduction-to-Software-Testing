package frontend.declaration.variable.vardef;

import frontend.SyntaxNode;

/**
 * 变量定义 VarDef
 */
public class VarDef implements SyntaxNode {
    private final String name = "<VarDef>";
    private final VarDefEle varDefEle;

    public VarDef(VarDefEle varDefEle) {
        if (varDefEle == null) {
            throw new IllegalArgumentException("VarDefEle cannot be null");
        }
        this.varDefEle = varDefEle;
    }

    @Override
    public String syntaxOutput() {
        return varDefEle.syntaxOutput() + name + "\n";
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}