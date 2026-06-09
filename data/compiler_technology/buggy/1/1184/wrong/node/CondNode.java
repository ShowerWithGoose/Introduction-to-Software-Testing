package node;

public class CondNode implements TreeNode {
    private LOrExpNode node;

    public CondNode(LOrExpNode node) {
        this.node = node;
    }

    @Override
    public void print() {
        node.print();
        System.out.println("<Cond>");
    }

    public int getLine() {
        return node.getLine();
    }

    public TreeNode getNode() {
        return node;
    }
}
