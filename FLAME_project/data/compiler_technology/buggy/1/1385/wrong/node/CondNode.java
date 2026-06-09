package node;

import java.io.IOException;

public class CondNode {
    // Cond -> LOrExp

    private LOrExpNode lOrExpNode;

    public CondNode(LOrExpNode lOrExpNode) {
        this.lOrExpNode = lOrExpNode;
    }
    
    public void print() throws IOException {
        lOrExpNode.print();
        Io.Text.printWord("<Cond>");
    }


}
