package node;

import java.io.IOException;

public class ExpNode {
    // Exp -> AddExp

    private AddExpNode addExpNode;

    public ExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }
    
    public void print() throws IOException {
        addExpNode.print();
        Io.Text.printWord("<Exp>");
    }
}
