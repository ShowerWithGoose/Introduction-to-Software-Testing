package node;


import java.io.IOException;

public class ConstExpNode {
    // ConstExp -> AddExp

    private AddExpNode addExpNode;

    public ConstExpNode(AddExpNode addExpNode) {
        this.addExpNode = addExpNode;
    }
    
    public void print() throws IOException {
        addExpNode.print();
        Io.Text.printWord("<ConstExp>");
    }
    
}
