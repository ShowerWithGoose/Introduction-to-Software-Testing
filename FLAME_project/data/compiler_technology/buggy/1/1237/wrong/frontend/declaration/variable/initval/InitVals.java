package frontend.declaration.variable.initval;

import frontend.SyntaxNode;
import frontend.Token;
import frontend.expression.Exp;
import java.util.List;

/**
 * 初始化多个值 InitVals
 */
public class InitVals implements InitValEle {
    private final Token leftBrace;
    private final Exp first; // may not exist, 表示第一个数组元素
    private final List<Token> commas;
    private final List<Exp> exps; // 直接使用 Exp 表达式列表
    private final Token rightBrace;

    public InitVals(Token leftBrace, Exp first, List<Token> commas, List<Exp> exps, Token rightBrace) {
        if (leftBrace == null || rightBrace == null) {
            throw new IllegalArgumentException("Braces cannot be null");
        }
        if ((commas != null && exps != null) && commas.size() != exps.size()) {
            throw new IllegalArgumentException("Commas and exps lists must have the same size");
        }
        this.leftBrace = leftBrace;
        this.first = first;
        this.commas = commas;
        this.exps = exps;
        this.rightBrace = rightBrace;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftBrace.syntaxOutput());
        if (first != null) {
            sb.append(first.syntaxOutput());
            if (commas != null && exps != null) {
                for (int i = 0; i < commas.size(); i++) {
                    sb.append(commas.get(i).syntaxOutput());
                    sb.append(exps.get(i).syntaxOutput());
                }
            }
        }
        sb.append(rightBrace.syntaxOutput());
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}
