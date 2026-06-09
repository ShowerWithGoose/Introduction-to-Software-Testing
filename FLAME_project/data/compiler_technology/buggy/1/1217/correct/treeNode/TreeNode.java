package treeNode;

import java.util.ArrayList;
import java.util.List;

import frontend.LexType;

public class TreeNode {
    private LexType nodeType; // 节点类型，如 "VarDecl"、"AssignExpr" 等
    private String tokenValue; // 存储实际的 Token 值，若为非终结符节点则为 null
    private List<TreeNode> children; // 子节点列表

    public TreeNode(){}
    // 构造函数，适用于非终结符节点
    public TreeNode(LexType nodeType) {
        this.nodeType = nodeType;
        this.tokenValue = null; // 非终结符节点不需要具体值
        this.children = new ArrayList<>();
    }

    // 构造函数，适用于叶子节点（终结符节点）
    public TreeNode(LexType nodeType, String tokenValue) {
        this.nodeType = nodeType;
        this.tokenValue = tokenValue;
        this.children = new ArrayList<>();
    }

    // 添加子节点
    public void addChild(TreeNode child) {
        this.children.add(child);
    }

    // 获取节点类型
    public LexType getNodeType() {
        return nodeType;
    }

    // 获取 token 值（适用于叶子节点）
    public String getTokenValue() {
        return tokenValue;
    }

    // 获取子节点列表
    public List<TreeNode> getChildren() {
        return children;
    }

    // 输出语法树（递归打印）
    public void printTree(String indent) {
        if (tokenValue != null) {
            System.out.println(indent + nodeType + ": " + tokenValue);
        } else {
            System.out.println(indent + nodeType);
        }

        for (TreeNode child : children) {
            child.printTree(indent + "  ");
        }
    }

    // 树的深度遍历，返回节点总数
    public int getNodeCount() {
        int count = 1; // 当前节点
        for (TreeNode child : children) {
            count += child.getNodeCount();
        }
        return count;
    }

    // 判断是否为叶子节点
    public boolean isLeaf() {
        return children.isEmpty();
    }
}
