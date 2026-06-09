package node;

import java.util.ArrayList;

public class LValNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public LValNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<LVal>");
    }

    public Token getIdent() {
        return (Token) (nodes.get(0));
    }

    public ExpNode getExp() {
        if (nodes.size() > 1) {
            return (ExpNode) (nodes.get(2));
        }
        return null;
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }
}
