package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

import java.util.LinkedList;

/**
 * 表示加法表达式的类，实现了 SyntaxOutput 接口。
 */
public class AddExp implements SyntaxOutput {
    // 语法节点名称
    private static final String NODE_NAME = "<AddExp>";
    // 乘法表达式列表
    private LinkedList<MulExp> termList;
    // 运算符列表（加号或减号）
    private LinkedList<Token> operatorList;

    /**
     * 构造函数，初始化加法表达式的各个部分。
     *
     * @param termList      乘法表达式的列表
     * @param operatorList  运算符的列表
     */
    public AddExp(LinkedList<MulExp> termList, LinkedList<Token> operatorList) {
        this.termList = termList;
        this.operatorList = operatorList;
    }

    /**
     * 生成加法表达式的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        int termCount = termList.size();
        for (int index = 0; index < termCount; index++) {
            // 添加乘法表达式的语法字符串
            syntaxBuilder.append(termList.get(index).toSyntaxString());
            // 在多个项的情况下，添加节点名称
            if (termCount > 1 && index < termCount - 1) {
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
