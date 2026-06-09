package frontend.expression;

import frontend.SyntaxNode;
import frontend.declaration.constant.constinitval.ConstInitValEle;
import frontend.expression.multiexp.AddExp;

/**
 * 常量表达式 ConstExp
 */
public class ConstExp implements ConstInitValEle {
    private final String name = "<ConstExp>";
    private final AddExp addExp;

    public ConstExp(AddExp addExp) {
        if (addExp == null) {
            throw new IllegalArgumentException("AddExp cannot be null");
        }
        this.addExp = addExp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.syntaxOutput());
        sb.append(name).append("\n");
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}