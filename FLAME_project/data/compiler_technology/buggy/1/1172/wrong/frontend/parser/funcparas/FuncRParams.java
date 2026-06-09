package frontend.parser.funcparas;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.expression.AddExp;

import java.util.LinkedList;

/**
 * 表示函数实参列表的类，实现了 SyntaxOutput 接口。
 */
public class FuncRParams implements SyntaxOutput {
    // 语法名称常量
    private static final String SYNTAX_NAME = "<FuncRParams>";
    // 存储表达式的列表
    private LinkedList<AddExp> argExpressionList;
    // 存储逗号 Token 的列表
    private LinkedList<Token> delimiterTokens;

    /**
     * 构造函数，初始化表达式列表和逗号列表。
     *
     * @param argExpressionList 表达式列表
     * @param delimiterTokens   逗号 Token 列表
     */
    public FuncRParams(LinkedList<AddExp> argExpressionList, LinkedList<Token> delimiterTokens) {
        this.argExpressionList = argExpressionList;
        this.delimiterTokens = delimiterTokens;
    }

    /**
     * 生成函数实参列表的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        int totalArgs = argExpressionList.size();
        for (int idx = 0; idx < totalArgs; idx++) {
            // 添加表达式的语法字符串
            syntaxBuilder.append(argExpressionList.get(idx).toSyntaxString());
            syntaxBuilder.append("<Exp>\n");
            if (idx < delimiterTokens.size()) {
                // 添加逗号的语法字符串
                syntaxBuilder.append(delimiterTokens.get(idx).toSyntaxString());
            }
        }
        // 添加语法名称
        syntaxBuilder.append(SYNTAX_NAME).append("\n");
        return syntaxBuilder.toString();
    }

    // 冗余方法：获取实参数量
    public int getArgumentCount() {
        return argExpressionList.size();
    }
}
