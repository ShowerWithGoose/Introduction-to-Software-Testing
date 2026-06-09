package node;

import java.util.ArrayList;

public class ConstDefNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public ConstDefNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<ConstDef>");
    }

    public Token getIdent() {
        return ((Token) nodes.get(0));
    }

    public ConstExpNode getConstExpNode() {
        if (getType() == 1) {
            return (ConstExpNode) (nodes.get(2));
        }
        return null;
    }

    public ConstInitValNode getConstInitValNode() {
        if (nodes.get(nodes.size() -1) instanceof ConstInitValNode) {
            return (ConstInitValNode) (nodes.get(nodes.size() - 1));
        }
        return null;
    }

    public int getType() {

        if (nodes.get(2) instanceof ConstExpNode) {
            return 1; //数组
        }
        return 0; //变量
    }
    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }
}
