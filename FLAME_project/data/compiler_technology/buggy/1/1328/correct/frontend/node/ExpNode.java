package frontend.node;

import frontend.Parser;
import utils.MyIO;

public class ExpNode {
    // 表达式 Exp -> AddExp

    private AddExpNode addExpNode;

    public ExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }

    public AddExpNode getAddExpNode() {
        return addExpNode;
    }

    public void print() {
        addExpNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.Exp));
    }
}
