package frontend.parser.declaration;

/**
 * 表示声明的类，实现了 DeclItem 接口。
 */
public class Decl implements DeclItem {
    // 语法节点名称常量
    private static final String NODE_NAME = "<Decl>";
    // 声明项，可能是常量声明或变量声明
    private DeclItem declarationItem;

    /**
     * 构造函数，初始化声明项。
     *
     * @param declarationItem 声明项对象
     */
    public Decl(DeclItem declarationItem) {
        this.declarationItem = declarationItem;
    }

    /**
     * 生成声明的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        return this.declarationItem.toSyntaxString();
    }
}
