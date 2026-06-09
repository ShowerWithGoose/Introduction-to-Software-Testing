package frontend.parser.expression;

import frontend.lexer.Token;

/**
 * 表示基本表达式的类，包括括号表达式、左值和常量。
 */
public class PrimaryExp {
    // 语法节点名称常量
    private static final String NODE_NAME = "<PrimaryExp>";
    // 左括号 Token（可选）
    private Token leftParenToken;
    // 加法表达式（可选）
    private AddExp innerExpression;
    // 右括号 Token（可选）
    private Token rightParenToken;
    // 左值（可选）
    private Lval lValue;
    // 整数常量 Token（可选）
    private Token intConstToken;
    // 字符常量 Token（可选）
    private Token charConstToken;

    /**
     * 构造函数，初始化基本表达式的各个部分。
     *
     * @param leftParenToken  左括号 Token（可选）
     * @param innerExpression 加法表达式（可选）
     * @param rightParenToken 右括号 Token（可选）
     * @param lValue          左值（可选）
     * @param intConstToken   整数常量 Token（可选）
     * @param charConstToken  字符常量 Token（可选）
     */
    public PrimaryExp(Token leftParenToken, AddExp innerExpression, Token rightParenToken,
                      Lval lValue, Token intConstToken, Token charConstToken) {
        this.leftParenToken = leftParenToken;
        this.innerExpression = innerExpression;
        this.rightParenToken = rightParenToken;
        this.lValue = lValue;
        this.intConstToken = intConstToken;
        this.charConstToken = charConstToken;
    }

    /**
     * 生成基本表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        if (leftParenToken != null) {
            syntaxBuilder.append(leftParenToken.toSyntaxString());
        }
        if (innerExpression != null) {
            syntaxBuilder.append(innerExpression.toSyntaxString());
            syntaxBuilder.append("<Exp>\n");
        }
        if (rightParenToken != null) {
            syntaxBuilder.append(rightParenToken.toSyntaxString());
        }
        if (lValue != null) {
            syntaxBuilder.append(lValue.toSyntaxString());
        }
        if (intConstToken != null) {
            syntaxBuilder.append(intConstToken.toSyntaxString());
            syntaxBuilder.append("<Number>\n");
        }
        if (charConstToken != null) {
            syntaxBuilder.append(charConstToken.toSyntaxString());
            syntaxBuilder.append("<Character>\n");
        }
        // 添加节点名称
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
