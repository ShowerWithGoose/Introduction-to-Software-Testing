package node;

import java.util.ArrayList;

public class ForStmtNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public ForStmtNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<ForStmt>");
    }

    public LValNode getLVal() {
        return (LValNode) (nodes.get(0));
    }

    public ExpNode getExp() {
        return  (ExpNode) (nodes.get(2));
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }
}
