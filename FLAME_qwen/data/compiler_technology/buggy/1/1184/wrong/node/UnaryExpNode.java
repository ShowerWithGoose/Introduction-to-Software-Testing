package node;

import java.util.ArrayList;

public class UnaryExpNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public UnaryExpNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<UnaryExp>");
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }

    public Token getIdent() {
        for (TreeNode t : nodes) {
            if (t instanceof Token && ((Token) t).isIdent()) {
                return (Token) t;
            }
        }
        return null;
    }

    public FuncRParamsNode getFuncRParams() {
        for (TreeNode t : nodes) {
            if (t instanceof FuncRParamsNode) {
                return (FuncRParamsNode) t;
            }
        }
        return null;
    }
}
