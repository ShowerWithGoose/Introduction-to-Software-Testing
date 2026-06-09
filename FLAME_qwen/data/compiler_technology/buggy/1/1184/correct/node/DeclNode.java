package node;

import java.util.ArrayList;

public class DeclNode implements TreeNode {
    private TreeNode node;

    public DeclNode(TreeNode node) {
        this.node = node;
    }

    public void print() {

        node.print();
        //System.out.println("<Decl>");
    }
    public int getLine() {
        return node.getLine();
    }

    public TreeNode getNode() {
        return node;
    }

    public int getDeclType() {
        if (node instanceof ConstDeclNode) {
            return 0;
        }
        return  1;
    }
}
