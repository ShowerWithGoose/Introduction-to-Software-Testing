package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.expression.AddExp;
import frontend.parser.expression.Lval;

/**
 * 表示 for 循环中的语句，实现了 SyntaxOutput 接口。
 */
public class ForStmt implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<ForStmt>";
    // 左值（循环变量）
    private Lval loopVariable;
    // 赋值号 Token
    private Token assignToken;
    // 表达式（循环初始值或条件）
    private AddExp expression;

    /**
     * 构造函数，初始化 ForStmt 对象。
     *
     * @param loopVariable 左值（循环变量）
     * @param assignToken  赋值号 Token
     * @param expression   表达式
     */
    public ForStmt(Lval loopVariable, Token assignToken, AddExp expression) {
        this.loopVariable = loopVariable;
        this.assignToken = assignToken;
        this.expression = expression;
    }

    /**
     * 生成 for 语句的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        syntaxBuilder.append(loopVariable.toSyntaxString());
        syntaxBuilder.append(assignToken.toSyntaxString());
        syntaxBuilder.append(expression.toSyntaxString());
        syntaxBuilder.append("<Exp>\n");
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
