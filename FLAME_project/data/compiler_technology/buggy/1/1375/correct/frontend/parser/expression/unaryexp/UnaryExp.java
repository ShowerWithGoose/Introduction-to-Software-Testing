package frontend.parser.expression.unaryexp;

import frontend.parser.SyntaxNode;

public class UnaryExp implements SyntaxNode {
    public final String name ="<UnaryExp>";
    public UnaryExpEle unaryExpEle;
    public UnaryExp(UnaryExpEle unaryExpEle) {
        this.unaryExpEle = unaryExpEle;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryExpEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        return this.unaryExpEle.my_line_num();
    }
}
