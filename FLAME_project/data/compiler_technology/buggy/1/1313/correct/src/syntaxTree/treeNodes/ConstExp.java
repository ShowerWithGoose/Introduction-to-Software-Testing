package src.syntaxTree.treeNodes;

import src.syntaxTree.STNode;

/**
 * 常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量
 */
public class ConstExp extends STNode {
    public AddExp addExp;
}
