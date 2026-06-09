package frontend;

import java.util.ArrayList;
import java.util.List;

public class ParseTreeNode {
    private String name; // 节点名称（非终结符或终结符）
    private List<ParseTreeNode> children; // 子节点列表

    // 静态变量存储语法树根节点
    private static ParseTreeNode rootNode;

    // 构造函数，适用于非终结符
    public ParseTreeNode(String name) {
        this.name = name;
        this.children = new ArrayList<>();
    }

    // 设置静态的语法树根节点
    public static void setRootNode(ParseTreeNode root) {
        rootNode = root;
    }

    // 获取静态的语法树根节点
    public static ParseTreeNode getRootNode() {
        return rootNode;
    }

    // 添加子节点
    public void addChild(ParseTreeNode child) {
        children.add(child);
    }

    // 获取节点名称
    public String getName() {
        return name;
    }

    // 获取子节点列表
    public List<ParseTreeNode> getChildren() {
        return children;
    }

    // 获取最近的一个子节点
    public ParseTreeNode getLastChild() {
        if (!children.isEmpty()) {
            return children.get(children.size() - 1);
        }
        return null; // 如果没有子节点，返回null
    }

    // 删除最近的一个子节点
    public boolean removeLastChild() {
        if (!children.isEmpty()) {
            children.remove(children.size() - 1);
            return true;
        }
        return false; // 如果没有子节点，返回false
    }

    // 打印语法树
    public void printTree(String indent) {
        System.out.println(indent + name);
        for (ParseTreeNode child : children) {
            child.printTree(indent + "  ");
        }
    }
}
