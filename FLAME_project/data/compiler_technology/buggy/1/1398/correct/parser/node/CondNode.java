package parser.node;

import parser.NodeType;

public class CondNode {
    LOrExpNode lOrExpNode;

    public CondNode(LOrExpNode lOrExpNode) {
        this.lOrExpNode = lOrExpNode;
    }
    public void print() {
        lOrExpNode.print();
        System.out.println(NodeType.Cond);
    }
}
