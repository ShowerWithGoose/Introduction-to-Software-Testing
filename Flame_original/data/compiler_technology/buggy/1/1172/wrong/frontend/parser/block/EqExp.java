package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

import java.util.LinkedList;

/**
 * 表示等价表达式的类，实现了 SyntaxOutput 接口。
 */
public class EqExp implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<EqExp>";
    // 关系表达式列表
    private LinkedList<RelExp> relExpList;
    // 等价操作符 Token 列表
    private LinkedList<Token> eqOperatorTokens;

    /**
     * 构造函数，初始化 EqExp 对象。
     *
     * @param relExpList        关系表达式列表
     * @param eqOperatorTokens  等价操作符 Token 列表
     */
    public EqExp(LinkedList<RelExp> relExpList, LinkedList<Token> eqOperatorTokens) {
        this.relExpList = relExpList;
        this.eqOperatorTokens = eqOperatorTokens;
    }

    /**
     * 生成等价表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        int expCount = relExpList.size();
        for (int index = 0; index < expCount; index++) {
            syntaxBuilder.append(relExpList.get(index).toSyntaxString());
            if (expCount > 1 && index < expCount - 1) {
                syntaxBuilder.append(NODE_NAME).append("\n");
            }
            if (index < eqOperatorTokens.size()) {
                syntaxBuilder.append(eqOperatorTokens.get(index).toSyntaxString());
            }
        }
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
