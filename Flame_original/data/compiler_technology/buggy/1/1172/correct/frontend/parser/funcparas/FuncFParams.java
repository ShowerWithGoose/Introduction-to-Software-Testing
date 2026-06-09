package frontend.parser.funcparas;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

import java.util.LinkedList;

/**
 * 表示函数形式参数列表的类，实现了 SyntaxOutput 接口。
 */
public class FuncFParams implements SyntaxOutput {
    // 语法名称常量
    private static final String SYNTAX_NAME = "<FuncFParams>";
    // 存储函数形式参数的列表
    private LinkedList<FuncFParam> paramList;
    // 存储逗号 Token 的列表
    private LinkedList<Token> separatorTokens;

    /**
     * 构造函数，初始化参数列表和逗号列表。
     *
     * @param paramList       函数形式参数列表
     * @param separatorTokens 逗号 Token 列表
     */
    public FuncFParams(LinkedList<FuncFParam> paramList, LinkedList<Token> separatorTokens) {
        this.paramList = paramList;
        this.separatorTokens = separatorTokens;
    }

    /**
     * 生成函数形式参数列表的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        int totalParams = paramList.size();
        for (int index = 0; index < totalParams; index++) {
            // 添加参数的语法字符串
            syntaxBuilder.append(paramList.get(index).toSyntaxString());
            if (index < separatorTokens.size()) {
                // 添加逗号的语法字符串
                syntaxBuilder.append(separatorTokens.get(index).toSyntaxString());
            } else if (index < totalParams - 1) {
                // 冗余代码：检查是否缺少逗号，实际情况下不会发生
                System.err.println("Warning: Missing comma between parameters at index " + index);
            }
        }
        // 添加语法名称
        syntaxBuilder.append(SYNTAX_NAME).append("\n");
        return syntaxBuilder.toString();
    }

    // 冗余方法：获取参数数量
    public int getParameterCount() {
        return paramList.size();
    }
}
