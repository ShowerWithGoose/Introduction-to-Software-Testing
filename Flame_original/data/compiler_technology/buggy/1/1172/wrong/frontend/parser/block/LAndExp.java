package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

import java.util.LinkedList;

/**
 * 表示逻辑与表达式的类，实现了 SyntaxOutput 接口。
 */
public class LAndExp implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<LAndExp>";
    // 等价表达式列表
    private LinkedList<EqExp> eqExpList;
    // 逻辑与操作符 Token 列表
    private LinkedList<Token> andOperatorTokens;

    /**
     * 构造函数，初始化 LAndExp 对象。
     *
     * @param eqExpList          等价表达式列表
     * @param andOperatorTokens  逻辑与操作符 Token 列表
     */
    public LAndExp(LinkedList<EqExp> eqExpList, LinkedList<Token> andOperatorTokens) {
        this.eqExpList = eqExpList;
        this.andOperatorTokens = andOperatorTokens;
    }

    /**
     * 生成逻辑与表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        int expCount = eqExpList.size();
        for (int index = 0; index < expCount; index++) {
            syntaxBuilder.append(eqExpList.get(index).toSyntaxString());
            if (expCount > 1 && index < expCount - 1) {
                syntaxBuilder.append(NODE_NAME).append("\n");
            }
            if (index < andOperatorTokens.size()) {
                syntaxBuilder.append(andOperatorTokens.get(index).toSyntaxString());
            }
        }
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
