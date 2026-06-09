package frontend.parser.expression.unaryexp;

import frontend.parser.SyntaxNode;

/**
 * UnaryExp 一元表达式类
 * <AddExp> -> <PrimaryExp> | <Ident> '(' [<FuncRParams> ')' | <UnaryOp> <UnaryExp>
 */
public class UnaryExp implements SyntaxNode {
    /**
     * 属性：
     * name 该语法类名
     * unaryExpEle <UnaryExp>分支
     */
    private final String name = "<UnaryExp>";
    private UnaryExpEle unaryExpEle;

    public UnaryExp(UnaryExpEle unaryExpEle) {
        this.unaryExpEle = unaryExpEle;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryExpEle.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
