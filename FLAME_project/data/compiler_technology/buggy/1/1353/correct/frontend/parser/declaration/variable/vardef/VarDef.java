package frontend.parser.declaration.variable.vardef;

import frontend.parser.SyntaxNode;

/**
 * VarDef 变量定义类
 * <VarDef> -> <Ident> [ '[' <ConstExp> ']' ] | <Ident> [ '[' <ConstExp> ']' ] '=' <InitVal>
 */
public class VarDef implements SyntaxNode {
    private final String name = "<VarDef>";
    private VarDefEle varDefEle;

    public VarDef(VarDefEle varDefEle) {
        this.varDefEle = varDefEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.varDefEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
