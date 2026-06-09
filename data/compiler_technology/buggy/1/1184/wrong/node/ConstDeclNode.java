package node;

import java.util.ArrayList;

public class ConstDeclNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public ConstDeclNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<ConstDecl>");
    }

    public ArrayList<ConstDefNode> getConstDef() {
        ArrayList<ConstDefNode> constDefNodes = new ArrayList<>();
        for (TreeNode t :nodes) {
            if (t instanceof ConstDefNode) {
                constDefNodes.add((ConstDefNode) t);
            }
        }
        return constDefNodes;
    }

    public int getType() {
        BTypeNode bTypeNode = (BTypeNode) (nodes.get(1));
        Token token = (Token) (bTypeNode.getNode());
        if (token.getTokenType().equals(TokenType.INTTK)) {
            return 0;
        }
        return 1;
    }

    public int getErrorLine(char type) {
        switch (type) {
            case 'i':
                return nodes.get(nodes.size() - 1).getLine();
            default:
                break;
        }
        return 0;
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }
}
