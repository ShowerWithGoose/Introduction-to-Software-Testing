package frontend.parser.declaration.variable.vardef;

import frontend.parser.SyntaxNode;

public class VarDef implements SyntaxNode {
    public final String name = "<VarDef>";
    public VarDefEle varDefEle;

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
    public int my_line_num() {
        return this.varDefEle.my_line_num();
    }
}
