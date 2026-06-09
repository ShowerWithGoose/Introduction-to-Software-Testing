package frontend.parser.declaration.variable.initval;

import frontend.parser.SyntaxNode;

public class InitVal implements SyntaxNode {
    public final String name = "<InitVal>";
    public InitValEle initValEle;

    public InitVal(InitValEle initValEle) {
        this.initValEle = initValEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.initValEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        return this.initValEle.my_line_num();
    }
}
