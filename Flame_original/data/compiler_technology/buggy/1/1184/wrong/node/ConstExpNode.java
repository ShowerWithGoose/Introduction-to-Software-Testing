package node;

public class ConstExpNode implements TreeNode {
    private AddExpNode node;

    public ConstExpNode(AddExpNode t) {
        this.node = t;
    }

    public void print() {

        node.print();
        System.out.println("<ConstExp>");
    }
    public int getLine() {
        return node.getLine();
    }

    public AddExpNode getNode() {
        return node;
    }
}
