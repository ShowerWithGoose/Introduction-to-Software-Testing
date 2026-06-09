package parser.node;

import parser.NodeType;

public class ExpNode {
    AddExpNode addExpNode;

    public ExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }
    public void print() {
        addExpNode.print();
        System.out.println(NodeType.Exp);
    }
}
