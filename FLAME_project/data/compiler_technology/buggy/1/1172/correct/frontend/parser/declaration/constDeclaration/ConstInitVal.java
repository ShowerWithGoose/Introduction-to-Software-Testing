package frontend.parser.declaration.constDeclaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.expression.ConstExp;

import java.util.LinkedList;

/**
 * 表示常量初始化值的类，实现了 SyntaxOutput 接口。
 */
public class ConstInitVal implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<ConstInitVal>";
    // 常量表达式列表
    private LinkedList<ConstExp> constExpList;
    // 左大括号 Token（可选）
    private Token leftBraceToken;
    // 右大括号 Token（可选）
    private Token rightBraceToken;
    // 逗号 Token 列表（用于分隔常量表达式）
    private LinkedList<Token> commaTokenList;
    // 字符串常量 Token（可选）
    private Token stringConstToken;

    /**
     * 构造函数，初始化常量初始化值的各个部分。
     *
     * @param constExpList 常量表达式列表
     * @param leftBraceToken 左大括号 Token（可选）
     * @param rightBraceToken 右大括号 Token（可选）
     * @param commaTokenList 逗号 Token 列表
     * @param stringConstToken 字符串常量 Token（可选）
     */
    public ConstInitVal(LinkedList<ConstExp> constExpList, Token leftBraceToken, Token rightBraceToken,
                        LinkedList<Token> commaTokenList, Token stringConstToken) {
        this.constExpList = constExpList;
        this.leftBraceToken = leftBraceToken;
        this.rightBraceToken = rightBraceToken;
        this.commaTokenList = commaTokenList;
        this.stringConstToken = stringConstToken;
    }

    /**
     * 生成常量初始化值的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        if (leftBraceToken != null) {
            syntaxBuilder.append(leftBraceToken.toSyntaxString());
        }
        int expCount = constExpList.size();
        for (int index = 0; index < expCount; index++) {
            // 添加常量表达式的语法字符串
            syntaxBuilder.append(constExpList.get(index).toSyntaxString());
            if (index < commaTokenList.size()) {
                // 添加逗号的语法字符串
                syntaxBuilder.append(commaTokenList.get(index).toSyntaxString());
            }
        }
        if (stringConstToken != null) {
            syntaxBuilder.append(stringConstToken.toSyntaxString());
        }
        if (rightBraceToken != null) {
            syntaxBuilder.append(rightBraceToken.toSyntaxString());
        }
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
