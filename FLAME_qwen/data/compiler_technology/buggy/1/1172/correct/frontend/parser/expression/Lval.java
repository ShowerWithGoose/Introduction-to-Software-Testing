package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

/**
 * 表示左值（变量或数组元素）的类，实现了 SyntaxOutput 接口。
 */
public class Lval implements SyntaxOutput {
    // 语法节点名称
    private static final String NODE_NAME = "<LVal>";
    // 标识符 Token
    private Token identifierToken;
    // 左中括号 Token（可选）
    private Token leftBracketToken;
    // 表达式（数组下标）
    private AddExp indexExpression;
    // 右中括号 Token（可选）
    private Token rightBracketToken;

    /**
     * 构造函数，初始化左值的各个部分。
     *
     * @param identifierToken  标识符 Token
     * @param leftBracketToken 左中括号 Token（可选）
     * @param indexExpression  下标表达式（可选）
     * @param rightBracketToken 右中括号 Token（可选）
     */
    public Lval(Token identifierToken, Token leftBracketToken, AddExp indexExpression, Token rightBracketToken) {
        this.identifierToken = identifierToken;
        this.leftBracketToken = leftBracketToken;
        this.indexExpression = indexExpression;
        this.rightBracketToken = rightBracketToken;
    }

    /**
     * 生成左值的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        // 添加标识符
        syntaxBuilder.append(identifierToken.toSyntaxString());
        // 如果有数组下标，添加中括号和表达式
        if (leftBracketToken != null) {
            syntaxBuilder.append(leftBracketToken.toSyntaxString());
            if (indexExpression != null) {
                syntaxBuilder.append(indexExpression.toSyntaxString());
                syntaxBuilder.append("<Exp>\n");
            }
            if (rightBracketToken != null) {
                syntaxBuilder.append(rightBracketToken.toSyntaxString());
            }
        }
        // 添加节点名称
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
