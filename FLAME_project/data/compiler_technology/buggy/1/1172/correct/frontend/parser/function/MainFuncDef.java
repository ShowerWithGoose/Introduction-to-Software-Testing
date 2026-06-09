package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.block.Block;

/**
 * 表示主函数定义的类，实现了 SyntaxOutput 接口。
 */
public class MainFuncDef implements SyntaxOutput {
    private static final String SYNTAX_NAME = "<MainFuncDef>";

    // "int" 关键字的 Token
    private Token intKeyword;
    private Token rightParen;
    // 主函数的函数体
    private Block mainFunctionBody;
    // "main" 关键字的 Token
    private Token mainKeyword;
    // 左括号 "(" 的 Token
    private Token leftParen;
    // 右括号 ")" 的 Token


    /**
     * 构造函数，初始化主函数定义的各个部分。
     *
     * @param intKeyword  "int" 关键字 Token
     * @param mainKeyword  "main" 关键字 Token
     * @param leftParen  左括号 Token
     * @param rightParen  右括号 Token
     * @param mainFunctionBody  主函数的函数体
     */
    public MainFuncDef(Token intKeyword, Token mainKeyword, Token leftParen,
                       Token rightParen, Block mainFunctionBody) {
        this.leftParen = leftParen;
        this.rightParen = rightParen;
        this.mainFunctionBody = mainFunctionBody;
        this.intKeyword = intKeyword;
        this.mainKeyword = mainKeyword;

    }

    /**
     * 生成主函数定义的语法字符串表示。
     *
     * @return 主函数定义的语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        // 添加 "int" 关键字
        syntaxBuilder.append(intKeyword.toSyntaxString());
        // 添加 "main" 关键字
        syntaxBuilder.append(mainKeyword.toSyntaxString());
        // 添加左括号 "("
        syntaxBuilder.append(leftParen.toSyntaxString());
        // 添加右括号 ")"
        syntaxBuilder.append(rightParen.toSyntaxString());
        // 添加函数体
        syntaxBuilder.append(mainFunctionBody.toSyntaxString());
        // 添加语法名称
        syntaxBuilder.append(SYNTAX_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
