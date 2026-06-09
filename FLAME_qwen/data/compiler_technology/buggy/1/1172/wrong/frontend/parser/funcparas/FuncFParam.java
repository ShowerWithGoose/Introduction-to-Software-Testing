package frontend.parser.funcparas;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

/**
 * 表示函数形式参数的类，实现了 SyntaxOutput 接口。
 */
public class FuncFParam implements SyntaxOutput {
    // 语法名称常量
    private static final String SYNTAX_NAME = "<FuncFParam>";
    // 基本类型的 Token，例如 int、char 等
    private Token typeToken;
    // 标识符 Token，表示参数名称
    private Token nameToken;
    // 左中括号 Token，表示数组参数的开始
    private Token leftBracketToken;
    // 右中括号 Token，表示数组参数的结束
    private Token rightBracketToken;

    /**
     * 构造函数，初始化函数形式参数的各个部分。
     *
     * @param typeToken         基本类型的 Token
     * @param nameToken         参数名称的 Token
     * @param leftBracketToken  左中括号的 Token（可选）
     * @param rightBracketToken 右中括号的 Token（可选）
     */
    public FuncFParam(Token typeToken, Token nameToken,
                      Token leftBracketToken, Token rightBracketToken) {
        this.typeToken = typeToken;
        this.nameToken = nameToken;
        this.leftBracketToken = leftBracketToken;
        this.rightBracketToken = rightBracketToken;
    }

    /**
     * 生成函数形式参数的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        // 添加基本类型
        syntaxBuilder.append(typeToken.toSyntaxString());
        // 添加标识符
        syntaxBuilder.append(nameToken.toSyntaxString());
        // 添加左中括号（如果存在）
        if (leftBracketToken != null) {
            syntaxBuilder.append(leftBracketToken.toSyntaxString());
            // 冗余代码：检查右中括号是否存在，如果不存在，添加日志（实际上在解析阶段已经处理）
            if (rightBracketToken == null) {
                System.err.println("Warning: Missing right bracket for array parameter at line " + leftBracketToken.getLine());
            }
        }
        // 添加右中括号（如果存在）
        if (rightBracketToken != null) {
            syntaxBuilder.append(rightBracketToken.toSyntaxString());
        }
        // 添加语法名称
        syntaxBuilder.append(SYNTAX_NAME).append("\n");
        return syntaxBuilder.toString();
    }

    // 冗余方法：用于调试，实际项目中可能不需要
    private void debugPrint() {
        System.out.println("FuncFParam Debug Info:");
        System.out.println("Type Token: " + typeToken.toString());
        System.out.println("Name Token: " + nameToken.toString());
    }
}
