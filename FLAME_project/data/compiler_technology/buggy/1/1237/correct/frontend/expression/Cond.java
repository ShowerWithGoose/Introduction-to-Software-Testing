package frontend.expression;

import frontend.SyntaxNode;
import frontend.expression.multiexp.LOrExp;

/**
 * 条件表达式
 */
public class Cond implements SyntaxNode {
    private final String name = "<Cond>";
    private final LOrExp lorExp;

    public Cond(LOrExp lorExp) {
        if (lorExp == null) {
            throw new IllegalArgumentException("LOrExp cannot be null");
        }
        this.lorExp = lorExp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lorExp.syntaxOutput());
        sb.append(name).append("\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}