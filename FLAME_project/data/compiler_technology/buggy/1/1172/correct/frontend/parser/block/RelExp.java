package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.expression.AddExp;

import java.util.LinkedList;

/**
 * 表示关系表达式的类，实现了 SyntaxOutput 接口。
 */
public class RelExp implements SyntaxOutput {
    // 常量：语法节点名称
    private static final String NODE_NAME = "<RelExp>";
    // 存储加法表达式的列表
    private LinkedList<AddExp> additiveExpList;
    // 存储关系操作符的 Token 列表
    private LinkedList<Token> relationOperatorTokens;

    /**
     * 构造函数，初始化关系表达式的各个部分。
     *
     * @param additiveExpList        加法表达式列表
     * @param relationOperatorTokens 关系操作符 Token 列表
     */
    public RelExp(LinkedList<AddExp> additiveExpList, LinkedList<Token> relationOperatorTokens) {
        this.additiveExpList = additiveExpList;
        this.relationOperatorTokens = relationOperatorTokens;
    }

    /**
     * 生成关系表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        int expCount = additiveExpList.size();
        for (int index = 0; index < expCount; index++) {
            syntaxBuilder.append(additiveExpList.get(index).toSyntaxString());
            if (expCount > 1 && index < expCount - 1) {
                syntaxBuilder.append(NODE_NAME).append("\n");
            }
            if (index < relationOperatorTokens.size()) {
                syntaxBuilder.append(relationOperatorTokens.get(index).toSyntaxString());
            }
        }
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
