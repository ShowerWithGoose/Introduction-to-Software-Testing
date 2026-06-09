package frontend.parser.expression;

import frontend.parser.SyntaxNode;
import frontend.parser.expression.multiexp.LOrExp;

/**
 * 条件表达式
 */
public class Cond implements SyntaxNode {
    public final String name = "<Cond>";
    public LOrExp lorExp;

    public Cond(LOrExp lorExp) {
        this.lorExp = lorExp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lorExp.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num(){
        return lorExp.my_line_num();
    }
}
