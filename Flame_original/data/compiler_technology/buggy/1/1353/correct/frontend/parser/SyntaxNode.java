package frontend.parser;

/**
 * SyntaxNode 语法节点接口
 * 用于响应所有的语法节点
 * 所有的非终结符类均继承该接口，充分利用多态，形成一棵以SyntaxNode的子类为节点的语法树
 */
public interface SyntaxNode {
    /**
     * syntaxOutput()
     * 语法树输出方法，用于正确输出语法树的结果
     * @return 以该节点为根节点的子语法树的输出内容
     */
    String syntaxOutput();
}
