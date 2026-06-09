package node;

import java.util.ArrayList;

public class ExpNode implements TreeNode {
    private AddExpNode node;

    public ExpNode(AddExpNode t) {
        this.node = t;
    }

    public void print() {

        node.print();
        System.out.println("<Exp>");
    }
    public int getLine() {
        return node.getLine();
    }

    public AddExpNode getNode() {
        return node;
    }
}
