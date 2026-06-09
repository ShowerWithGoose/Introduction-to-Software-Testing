package frontend.Node;

import java.util.ArrayList;

public class Node extends ASTNode {
    private ParType parType;
    private Node parentNode;
    private ArrayList<ASTNode> childNode;

    public Node(ParType parType) {
        this.parType = parType;
        this.parentNode = null;
        this.childNode = new ArrayList<>();
    } // 非叶节点

    public void addChildNode(ASTNode node) {
        childNode.add(node);
    }

    public void setParentNode(Node parentNode) {
        this.parentNode = parentNode;
    }

    public ArrayList<ASTNode> getChildNode() {
        return childNode;
    }

    public ParType getParType() {
        return parType;
    }

    @Override
    public String toString() {
        return '<' + parType.toString() + '>';
    }
}
