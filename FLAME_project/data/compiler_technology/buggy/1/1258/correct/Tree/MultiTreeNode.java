/*package Tree;

import base.Keywords;
import base.Token;

import java.util.ArrayList;
import java.util.List;

public class MultiTreeNode {
    private List<MultiTreeNode> children; // 子节点列表
    private MultiTreeNode father;
    private ArrayList<Token> data; // 叶节点的数据
    private String type;

    public MultiTreeNode(String type,MultiTreeNode father) {
        this.children = new ArrayList<>();
        this.type = type;
        this.data = null; // 非叶节点默认没有数据
    }

    public MultiTreeNode(String data, String type,MultiTreeNode father) {
        this.children = new ArrayList<>();
        this.type = type;
        this.data = data; // 只有叶节点才有数据
    }

    // 添加子节点
    public void addChild(MultiTreeNode child) {
        children.add(child);
    }

    // 获取子节点列表
    public List<MultiTreeNode> getChildren() {
        return children;
    }

    // 判断是否是叶节点
    public boolean isLeaf() {
        return children.isEmpty();
    }

    // 获取叶节点的数据
    public String getData() {
        return data;
    }

    public MultiTreeNode getFather() {
        return father;
    }

    public void setValue(String value) {
        this.data = value;
    }
}*/
