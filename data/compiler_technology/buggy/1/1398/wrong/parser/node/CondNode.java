package parser.node;

public class CondNode {
    LOrExpNode lOrExpNode;

    public CondNode(LOrExpNode lOrExpNode) {
        this.lOrExpNode = lOrExpNode;
    }
    public void print() {
        lOrExpNode.print();
    }
}
