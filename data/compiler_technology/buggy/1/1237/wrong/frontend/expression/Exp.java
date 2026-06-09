package frontend.expression;

import frontend.SyntaxNode;
import frontend.declaration.variable.initval.InitValEle;
import frontend.expression.multiexp.AddExp;

/**
 * 表达式
 */
public class Exp implements InitValEle {
    private final String name = "<Exp>";
    private final AddExp addExp;

    public Exp(AddExp addExp) {
        if (addExp == null) {
            throw new IllegalArgumentException("AddExp cannot be null");
        }
        this.addExp = addExp;
    }

    public AddExp getAddExp() {
        return addExp;
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