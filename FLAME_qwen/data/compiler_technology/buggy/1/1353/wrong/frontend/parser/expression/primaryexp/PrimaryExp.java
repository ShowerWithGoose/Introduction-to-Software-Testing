package frontend.parser.expression.primaryexp;

import frontend.parser.expression.unaryexp.UnaryExpEle;

/**
 * PrimaryExp 基本表达式类
 * <PrimaryExp> -> '(' <Exp> ')' | <LVal> | <Number> | <Character>
 */
public class PrimaryExp implements UnaryExpEle {
    /**
     * 属性：
     * name 该语法类名
     * primaryExpEle <PrimaryExp>分支
     */
    private final String name = "<PrimaryExp>";
    private PrimaryExpEle primaryExpEle;

    public PrimaryExp(PrimaryExpEle primaryExpEle) {
        this.primaryExpEle = primaryExpEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.primaryExpEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
