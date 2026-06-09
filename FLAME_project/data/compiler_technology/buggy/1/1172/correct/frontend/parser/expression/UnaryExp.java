package frontend.parser.expression;

import frontend.lexer.*;
import frontend.parser.SyntaxOutput;
import frontend.parser.funcparas.FuncRParams;

/**
 * 表示一元表达式的类，实现了 SyntaxOutput 接口。
 */
public class UnaryExp implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<UnaryExp>";
    // 一元运算符 Token（可选）
    private Token unaryOperatorToken;
    // 递归的一元表达式（可选）
    private UnaryExp nestedUnaryExp;
    // 基本表达式（可选）
    private PrimaryExp primaryExpression;
    // 标识符 Token（可选）
    private Token identifierToken;
    // 左括号 Token（可选）
    private Token leftParenToken;
    // 函数实参列表（可选）
    private FuncRParams functionArguments;
    // 右括号 Token（可选）
    private Token rightParenToken;

    /**
     * 构造函数，初始化一元表达式的各个部分。
     *
     * @param unaryOperatorToken 一元运算符 Token（可选）
     * @param primaryExpression  基本表达式（可选）
     * @param nestedUnaryExp     递归的一元表达式（可选）
     * @param identifierToken    标识符 Token（可选）
     * @param leftParenToken     左括号 Token（可选）
     * @param functionArguments  函数实参列表（可选）
     * @param rightParenToken    右括号 Token（可选）
     */
    public UnaryExp(Token unaryOperatorToken, PrimaryExp primaryExpression, UnaryExp nestedUnaryExp,
                    Token identifierToken, Token leftParenToken, FuncRParams functionArguments, Token rightParenToken) {
        this.unaryOperatorToken = unaryOperatorToken;
        this.nestedUnaryExp = nestedUnaryExp;
        this.primaryExpression = primaryExpression;
        this.identifierToken = identifierToken;
        this.leftParenToken = leftParenToken;
        this.functionArguments = functionArguments;
        this.rightParenToken = rightParenToken;
    }

    /**
     * 生成一元表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        if (unaryOperatorToken != null) {
            syntaxBuilder.append(unaryOperatorToken.toSyntaxString());
            syntaxBuilder.append("<UnaryOp>\n");
        }
        if (nestedUnaryExp != null) {
            syntaxBuilder.append(nestedUnaryExp.toSyntaxString());
        }
        if (primaryExpression != null) {
            syntaxBuilder.append(primaryExpression.toSyntaxString());
        }
        if (identifierToken != null) {
            syntaxBuilder.append(identifierToken.toSyntaxString());
        }
        if (leftParenToken != null) {
            syntaxBuilder.append(leftParenToken.toSyntaxString());
        }
        if (functionArguments != null) {
            syntaxBuilder.append(functionArguments.toSyntaxString());
        }
        if (rightParenToken != null) {
            syntaxBuilder.append(rightParenToken.toSyntaxString());
        }
        // 添加节点名称
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
