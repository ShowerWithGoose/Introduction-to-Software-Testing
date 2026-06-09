package node;

import java.util.ArrayList;

public class PrimaryExpNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public PrimaryExpNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<PrimaryExp>");
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }
}
