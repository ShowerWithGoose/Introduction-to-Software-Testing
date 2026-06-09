package frontend.parser.declaration.varDeclaration;

import frontend.lexer.Token;
import frontend.parser.declaration.DeclItem;

import java.util.LinkedList;

/**
 * 表示变量声明，实现了 DeclItem 接口。
 */
public class VarDecl implements DeclItem {
    // 语法节点名称常量
    private static final String NODE_NAME = "<VarDecl>";
    // 基本类型 Token，例如 int、char
    private Token baseTypeToken;
    // 变量定义列表
    private LinkedList<VarDef> varDefList;
    // 逗号 Token 列表
    private LinkedList<Token> commaTokenList;
    // 分号 Token
    private Token semicolonToken;

    /**
     * 构造函数，初始化 VarDecl 对象。
     *
     * @param baseTypeToken   基本类型 Token
     * @param varDefList      变量定义列表
     * @param commaTokenList  逗号 Token 列表
     * @param semicolonToken  分号 Token
     */
    public VarDecl(Token baseTypeToken, LinkedList<VarDef> varDefList, LinkedList<Token> commaTokenList,
                   Token semicolonToken) {
        this.baseTypeToken = baseTypeToken;
        this.varDefList = varDefList;
        this.commaTokenList = commaTokenList;
        this.semicolonToken = semicolonToken;
    }

    /**
     * 生成变量声明的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        syntaxBuilder.append(baseTypeToken.toSyntaxString());
        int defCount = varDefList.size();
        for (int index = 0; index < defCount; index++) {
            syntaxBuilder.append(varDefList.get(index).toSyntaxString());
            if (index < commaTokenList.size()) {
                syntaxBuilder.append(commaTokenList.get(index).toSyntaxString());
            }
        }
        syntaxBuilder.append(semicolonToken.toSyntaxString());
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
