package frontend.parser.declaration.varDeclaration;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.expression.AddExp;

import java.util.LinkedList;

/**
 * 表示变量声明中的初始化值。
 */
public class InitVal implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<InitVal>";
    // 表达式列表
    private LinkedList<AddExp> expressionList;
    // 左大括号 Token（可选）
    private Token leftBraceToken;
    // 右大括号 Token（可选）
    private Token rightBraceToken;
    // 逗号 Token 列表（用于分隔表达式）
    private LinkedList<Token> commaTokenList;
    // 字符串常量 Token（可选）
    private Token stringConstToken;

    /**
     * 构造函数，初始化 InitVal 对象。
     *
     * @param expressionList   表达式列表
     * @param leftBraceToken   左大括号 Token
     * @param rightBraceToken  右大括号 Token
     * @param commaTokenList   逗号 Token 列表
     * @param stringConstToken 字符串常量 Token
     */
    public InitVal(LinkedList<AddExp> expressionList, Token leftBraceToken, Token rightBraceToken,
                   LinkedList<Token> commaTokenList, Token stringConstToken) {
        this.expressionList = expressionList;
        this.leftBraceToken = leftBraceToken;
        this.rightBraceToken = rightBraceToken;
        this.commaTokenList = commaTokenList;
        this.stringConstToken = stringConstToken;
    }

    /**
     * 生成初始化值的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        if (stringConstToken != null) {
            syntaxBuilder.append(stringConstToken.toSyntaxString());
        }
        if (leftBraceToken != null) {
            syntaxBuilder.append(leftBraceToken.toSyntaxString());
        }
        int exprCount = expressionList.size();
        for (int index = 0; index < exprCount; index++) {
            // 添加表达式的语法字符串
            syntaxBuilder.append(expressionList.get(index).toSyntaxString());
            syntaxBuilder.append("<Exp>\n");
            if (index < commaTokenList.size()) {
                // 添加逗号的语法字符串
                syntaxBuilder.append(commaTokenList.get(index).toSyntaxString());
            }
        }
        if (rightBraceToken != null) {
            syntaxBuilder.append(rightBraceToken.toSyntaxString());
        }
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
