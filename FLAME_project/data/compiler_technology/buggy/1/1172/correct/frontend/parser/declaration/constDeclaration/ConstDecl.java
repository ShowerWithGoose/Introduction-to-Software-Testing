package frontend.parser.declaration.constDeclaration;

import frontend.lexer.Token;
import frontend.parser.declaration.DeclItem;
import frontend.parser.declaration.constDeclaration.ConstDef;

import java.util.LinkedList;

/**
 * 表示常量声明的类，实现了 DeclItem 接口。
 */
public class ConstDecl implements DeclItem {
    // 语法节点名称常量
    private static final String NODE_NAME = "<ConstDecl>";
    // 关键字 const 的 Token
    private Token constKeyword;
    // 基本类型的 Token，例如 int、char 等
    private Token baseTypeToken;
    // 常量定义列表
    private LinkedList<ConstDef> constDefList;
    // 逗号 Token 列表，用于分隔多个常量定义
    private LinkedList<Token> commaTokenList;
    // 分号 Token，表示声明的结束
    private Token semicolonToken;

    /**
     * 构造函数，初始化常量声明的各个部分。
     *
     * @param constKeyword    关键字 const 的 Token
     * @param baseTypeToken   基本类型的 Token
     * @param constDefList    常量定义列表
     * @param commaTokenList  逗号 Token 列表
     * @param semicolonToken  分号 Token
     */
    public ConstDecl(Token constKeyword, Token baseTypeToken, LinkedList<ConstDef> constDefList,
                     LinkedList<Token> commaTokenList, Token semicolonToken) {
        this.constKeyword = constKeyword;
        this.baseTypeToken = baseTypeToken;
        this.constDefList = constDefList;
        this.commaTokenList = commaTokenList;
        this.semicolonToken = semicolonToken;
    }

    /**
     * 生成常量声明的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        syntaxBuilder.append(constKeyword.toSyntaxString());
        syntaxBuilder.append(baseTypeToken.toSyntaxString());
        int defCount = constDefList.size();
        for (int index = 0; index < defCount; index++) {
            // 添加常量定义的语法字符串
            syntaxBuilder.append(constDefList.get(index).toSyntaxString());
            if (index < commaTokenList.size()) {
                // 添加逗号的语法字符串
                syntaxBuilder.append(commaTokenList.get(index).toSyntaxString());
            }
        }
        syntaxBuilder.append(semicolonToken.toSyntaxString());
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
