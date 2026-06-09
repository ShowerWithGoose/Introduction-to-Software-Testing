package frontend.parser.declaration.varDeclaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.expression.ConstExp;

/**
 * 表示变量定义的类，实现了 SyntaxOutput 接口。
 */
public class VarDef implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<VarDef>";
    // 标识符 Token
    private Token identifierToken;
    // 左中括号 Token（可选）
    private Token leftBracketToken;
    // 常量表达式（数组大小，可选）
    private ConstExp arraySizeExpression;
    // 右中括号 Token（可选）
    private Token rightBracketToken;
    // 赋值号 Token（可选）
    private Token assignToken;
    // 初始化值（可选）
    private InitVal initialValue;

    /**
     * 构造函数，初始化变量定义的各个部分。
     *
     * @param identifierToken     标识符 Token
     * @param leftBracketToken    左中括号 Token（可选）
     * @param arraySizeExpression 常量表达式（数组大小，可选）
     * @param rightBracketToken   右中括号 Token（可选）
     * @param assignToken         赋值号 Token（可选）
     * @param initialValue        初始化值（可选）
     */
    public VarDef(Token identifierToken, Token leftBracketToken, ConstExp arraySizeExpression,
                  Token rightBracketToken, Token assignToken, InitVal initialValue) {
        this.identifierToken = identifierToken;
        this.leftBracketToken = leftBracketToken;
        this.arraySizeExpression = arraySizeExpression;
        this.rightBracketToken = rightBracketToken;
        this.assignToken = assignToken;
        this.initialValue = initialValue;
    }

    /**
     * 生成变量定义的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        syntaxBuilder.append(identifierToken.toSyntaxString());
        if (leftBracketToken != null) {
            syntaxBuilder.append(leftBracketToken.toSyntaxString());
        }
        if (arraySizeExpression != null) {
            syntaxBuilder.append(arraySizeExpression.toSyntaxString());
        }
        if (rightBracketToken != null) {
            syntaxBuilder.append(rightBracketToken.toSyntaxString());
        }
        if (assignToken != null) {
            syntaxBuilder.append(assignToken.toSyntaxString());
            syntaxBuilder.append(initialValue.toSyntaxString());
        }
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
