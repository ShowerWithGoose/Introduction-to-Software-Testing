package node;

import java.util.ArrayList;

public class VarDefNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public VarDefNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<VarDef>");
    }


    public Token getIdent() {
        return (Token) (nodes.get(0));
    }

    public int getType() {
        if (nodes.size() == 1) {
            return 0;
        }
        Token token = (Token) (nodes.get(1));
        if (token.getTokenType().equals(TokenType.LBRACK)) {
            return 1;
        }
        return 0;
    }

    public ConstExpNode getConstExp() {
        if (getType() == 1) {
            return (ConstExpNode) (nodes.get(2));
        }
        return null;
    }

    public InitValNode getInitVal() {
        if (nodes.size() == 3 && nodes.get(2) instanceof InitValNode) {
            return (InitValNode) (nodes.get(2));
        } else if (nodes.size() == 6 && nodes.get(5) instanceof InitValNode) {
            return (InitValNode) (nodes.get(5));
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
