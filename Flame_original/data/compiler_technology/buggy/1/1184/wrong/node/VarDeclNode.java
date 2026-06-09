package node;

import java.util.ArrayList;

public class VarDeclNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public VarDeclNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<VarDecl>");
    }

    public int getType() {
        BTypeNode bTypeNode = (BTypeNode) (nodes.get(0));
        Token token = (Token) (bTypeNode.getNode());
        if (token.getTokenType().equals(TokenType.INTTK)) {
            return 0;
        }
        return 1;
    }


    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }
}
