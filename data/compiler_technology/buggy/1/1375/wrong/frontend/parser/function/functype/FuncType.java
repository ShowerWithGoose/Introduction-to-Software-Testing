package frontend.parser.function.functype;

import frontend.parser.SyntaxNode;

public class FuncType implements SyntaxNode {
    public final String name="<FuncType>";
    public FuncTypeEle funcTypeEle;
    public FuncType(FuncTypeEle funcTypeEle) {this.funcTypeEle = funcTypeEle;}
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcTypeEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num(){
        return this.funcTypeEle.my_line_num();
    }
}
