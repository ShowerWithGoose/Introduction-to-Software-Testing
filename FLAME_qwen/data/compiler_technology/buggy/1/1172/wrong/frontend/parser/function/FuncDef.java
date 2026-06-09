package frontend.parser.function;


import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.funcparas.FuncFParams;
import frontend.parser.block.Block;
import frontend.lexer.*;
/**
 * 表示函数定义的类，实现了 SyntaxOutput 接口。
 */
public class FuncDef implements SyntaxOutput {
    private static final String SYNTAX_NAME = "<FuncDef>";

    // 函数类型，如 int、void 等
    private Token returnType;
    // 函数标识符，即函数名
    private Token functionName;
    private FuncFParams parameters;
    // 右括号 ")"
    private Token rightParen;
    // 函数体
    private Block functionBody;
    // 左括号 "("
    private Token leftParen;
    // 函数参数列表


    /**
     * 构造函数，初始化函数定义的各个部分。
     *
     * @param returnType  函数返回类型的 Token
     * @param functionName  函数名的 Token
     * @param leftParen  左括号的 Token
     * @param parameters  函数参数列表
     * @param rightParen  右括号的 Token
     * @param functionBody  函数体
     */
    public FuncDef(Token returnType, Token functionName, Token leftParen,
                   FuncFParams parameters, Token rightParen, Block functionBody) {
        this.returnType = returnType;
        this.functionName = functionName;
        this.leftParen = leftParen;
        this.parameters = parameters;
        this.rightParen = rightParen;
        this.functionBody = functionBody;
    }

    /**
     * 生成函数定义的语法字符串表示。
     *
     * @return 函数定义的语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        // 添加函数返回类型
        syntaxBuilder.append(returnType.toSyntaxString());
        syntaxBuilder.append("<FuncType>\n");
        // 添加函数名
        syntaxBuilder.append(functionName.toSyntaxString());
        // 添加左括号
        syntaxBuilder.append(leftParen.toSyntaxString());
        // 添加函数参数列表（如果有）
        if (parameters != null) {
            syntaxBuilder.append(parameters.toSyntaxString());
        }
        // 添加右括号
        syntaxBuilder.append(rightParen.toSyntaxString());
        // 添加函数体
        syntaxBuilder.append(functionBody.toSyntaxString());
        // 添加语法名称
        syntaxBuilder.append(SYNTAX_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
