package frontend.parser.expression;

import frontend.parser.SyntaxOutput;

/**
 * 表示常量表达式的类，实现了 SyntaxOutput 接口。
 */
public class ConstExp implements SyntaxOutput {
    // 语法节点名称
    private static final String NODE_NAME = "<ConstExp>";
    // 加法表达式
    private AddExp expression;

    /**
     * 构造函数，初始化常量表达式。
     *
     * @param expression 加法表达式对象
     */
    public ConstExp(AddExp expression) {
        this.expression = expression;
    }

    /**
     * 生成常量表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        // 添加加法表达式的语法字符串
        syntaxBuilder.append(expression.toSyntaxString());
        // 添加节点名称
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
