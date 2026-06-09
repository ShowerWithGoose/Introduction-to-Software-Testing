package frontend.parser.declaration.constant.constinitval;

import frontend.parser.SyntaxNode;

public class ConstInitVal implements SyntaxNode {
    public final String name = "<ConstInitVal>";
    public ConstInitValEle constInitValEle;
    public ConstInitVal(ConstInitValEle constInitValEle) {
        this.constInitValEle = constInitValEle;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(constInitValEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        return this.constInitValEle.my_line_num();
    }
}
