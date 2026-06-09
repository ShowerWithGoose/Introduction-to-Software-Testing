package frontend.parser.block;

import frontend.parser.SyntaxOutput;
import frontend.parser.declaration.Decl;

/**
 * 表示代码块中的一项，可以是声明或语句。
 */
public class BlockItem implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<BlockItem>";
    // 声明（可选）
    private Decl declaration;
    // 语句（可选）
    private Stmt statement;

    /**
     * 构造函数，初始化代码块项。
     *
     * @param declaration 声明（可选）
     * @param statement   语句（可选）
     */
    public BlockItem(Decl declaration, Stmt statement) {
        this.declaration = declaration;
        this.statement = statement;
    }

    /**
     * 生成代码块项的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        if (declaration != null) {
            syntaxBuilder.append(declaration.toSyntaxString());
        }
        if (statement != null) {
            syntaxBuilder.append(statement.toSyntaxString());
        }
        return syntaxBuilder.toString();
    }
}
