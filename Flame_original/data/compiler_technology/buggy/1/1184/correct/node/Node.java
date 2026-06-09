package node;

import java.util.ArrayList;

public class Node implements TreeNode {
    private ArrayList<TreeNode> nodeList;

    public Node() {
        this.nodeList = new ArrayList<>();
    }

    @Override
    public void print() {
        for (TreeNode t : nodeList) {
            t.print();
        }
    }

    public int getLine() {
        return 0;
    }
}
