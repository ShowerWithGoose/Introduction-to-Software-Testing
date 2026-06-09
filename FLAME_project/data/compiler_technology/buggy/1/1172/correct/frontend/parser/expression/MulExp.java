package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

import java.util.LinkedList;

/**
 * 表示乘法表达式的类，实现了 SyntaxOutput 接口。
 */
public class MulExp implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<MulExp>";
    // 一元表达式列表
    private LinkedList<UnaryExp> factorList;
    // 运算符列表（乘号、除号或取模）
    private LinkedList<Token> operatorList;

    /**
     * 构造函数，初始化乘法表达式的各个部分。
     *
     * @param factorList   一元表达式列表
     * @param operatorList 运算符列表
     */
    public MulExp(LinkedList<UnaryExp> factorList, LinkedList<Token> operatorList) {
        this.factorList = factorList;
        this.operatorList = operatorList;
    }

    /**
     * 生成乘法表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        int factorCount = factorList.size();
        for (int index = 0; index < factorCount; index++) {
            // 添加一元表达式的语法字符串
            syntaxBuilder.append(factorList.get(index).toSyntaxString());
            // 在多个项的情况下，添加节点名称
            if (factorCount > 1 && index < factorCount - 1) {
                syntaxBuilder.append(NODE_NAME).append("\n");
            }
            // 添加运算符的语法字符串
            if (index < operatorList.size()) {
                syntaxBuilder.append(operatorList.get(index).toSyntaxString());
            }
        }
        // 添加节点名称
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
