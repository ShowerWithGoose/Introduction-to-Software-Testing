package node;

import java.util.ArrayList;

public class BlockItemNode implements TreeNode {
    private TreeNode node;

    public BlockItemNode(TreeNode node) {
        this.node = node;
    }

    @Override
    public void print() {
        node.print();
        //System.out.println("<BlockItem>");
    }

    public int getLine() {
        return node.getLine();
    }

    public TreeNode getNode() {
        return node;
    }
}
