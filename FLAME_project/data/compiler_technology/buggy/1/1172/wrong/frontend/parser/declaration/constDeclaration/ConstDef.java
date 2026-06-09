package frontend.parser.declaration.constDeclaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.expression.ConstExp;

import java.util.LinkedList;

/**
 * 表示常量定义的类，实现了 SyntaxOutput 接口。
 */
public class ConstDef implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<ConstDef>";
    // 标识符 Token
    private Token identifierToken;
    // 左中括号 Token（可选）
    private Token leftBracketToken;
    // 常量表达式（数组大小，可选）
    private ConstExp arraySizeExp;
    // 右中括号 Token（可选）
    private Token rightBracketToken;
    // 等号 Token
    private Token assignToken;
    // 常量初始化值
    private ConstInitVal constInitValue;

    /**
     * 构造函数，初始化常量定义的各个部分。
     *
     * @param identifierToken 标识符 Token
     * @param leftBracketToken 左中括号 Token（可选）
     * @param arraySizeExp 常量表达式（可选）
     * @param rightBracketToken 右中括号 Token（可选）
     * @param assignToken 等号 Token
     * @param constInitValue 常量初始化值
     */
    public ConstDef(Token identifierToken, Token leftBracketToken, ConstExp arraySizeExp,
                    Token rightBracketToken, Token assignToken, ConstInitVal constInitValue) {
        this.identifierToken = identifierToken;
        this.leftBracketToken = leftBracketToken;
        this.arraySizeExp = arraySizeExp;
        this.rightBracketToken = rightBracketToken;
        this.assignToken = assignToken;
        this.constInitValue = constInitValue;
    }

    /**
     * 生成常量定义的语法字符串表示。
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
        if (arraySizeExp != null) {
            syntaxBuilder.append(arraySizeExp.toSyntaxString());
        }
        if (rightBracketToken != null) {
            syntaxBuilder.append(rightBracketToken.toSyntaxString());
        }
        syntaxBuilder.append(assignToken.toSyntaxString());
        syntaxBuilder.append(constInitValue.toSyntaxString());
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
