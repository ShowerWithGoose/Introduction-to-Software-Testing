package node;

import java.util.ArrayList;

public class CompUnitNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public CompUnitNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<CompUnit>");
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }
}
