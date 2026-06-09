package parser.node;

import parser.NodeType;

public class ConstExpNode {
    AddExpNode addExpNode;

    public ConstExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }
    public void print() {
        addExpNode.print();
        System.out.println(NodeType.ConstExp);
    }
}
