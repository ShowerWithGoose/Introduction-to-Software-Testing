package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

import java.util.LinkedList;

/**
 * 表示逻辑或表达式的类，实现了 SyntaxOutput 接口。
 */
public class LOrExp implements SyntaxOutput {
    // 常量：语法节点名称
    private static final String NODE_NAME = "<LOrExp>";
    // 存储逻辑与表达式的列表
    private LinkedList<LAndExp> andExpressionList;
    // 存储逻辑或操作符的 Token 列表
    private LinkedList<Token> orOperatorTokens;

    /**
     * 构造函数，初始化逻辑或表达式的各个部分。
     *
     * @param andExpressionList 逻辑与表达式列表
     * @param orOperatorTokens  逻辑或操作符 Token 列表
     */
    public LOrExp(LinkedList<LAndExp> andExpressionList, LinkedList<Token> orOperatorTokens) {
        this.andExpressionList = andExpressionList;
        this.orOperatorTokens = orOperatorTokens;
    }

    /**
     * 生成逻辑或表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        int exprCount = andExpressionList.size();
        for (int index = 0; index < exprCount; index++) {
            syntaxBuilder.append(andExpressionList.get(index).toSyntaxString());
            if (exprCount > 1 && index < exprCount - 1) {
                syntaxBuilder.append(NODE_NAME).append("\n");
            }
            if (index < orOperatorTokens.size()) {
                syntaxBuilder.append(orOperatorTokens.get(index).toSyntaxString());
            }
        }
        syntaxBuilder.append(NODE_NAME).append("\n");
        syntaxBuilder.append("<Cond>\n");
        return syntaxBuilder.toString();
    }
}
