package frontend.node;

import frontend.Parser;
import utils.MyIO;

public class ConstExpNode {
    // 常量表达式 ConstExp -> AddExp

    private AddExpNode addExpNode;

    public ConstExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }

    public AddExpNode getAddExpNode() {
        return addExpNode;
    }

    public void print() {
        addExpNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.ConstExp));
    }
}
