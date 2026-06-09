package frontend;

import java.util.ArrayList;
import java.util.List;

public class Node {
    String name;
    List<Node> children;

    // 构造函数
    public Node(String name) {
        this.name = name;
        this.children = new ArrayList<>();
    }

    // 添加子节点的方法
    public void addChild(Node child) {
        this.children.add(child);
    }

}