package node;

import java.util.ArrayList;

public class FuncDefNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public FuncDefNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<FuncDef>");
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }

    public int getFuncType() {
        FuncTypeNode funcTypeNode = (FuncTypeNode) (nodes.get(0));
        Token t = (Token)(funcTypeNode.getNode());
        if (t.getTokenType().equals(TokenType.INTTK)) {
            return 0;
        } else if (t.getTokenType().equals(TokenType.CHARTK)) {
            return 1;
        } else {
            return 2;
        }
    }

    public BlockNode getBlock() {
        return (BlockNode) (nodes.get(nodes.size()-1));
    }

    public ArrayList<FuncFParamNode> getFuncFParams() {
        ArrayList<FuncFParamNode> paramNodes = new ArrayList<>();
        if (nodes.get(3) instanceof FuncFParamsNode) {
            ArrayList<TreeNode> tn = ((FuncFParamsNode)(nodes.get(3))).getNodes();
            for (TreeNode temp : tn) {
                if (temp instanceof FuncFParamNode) {
                    paramNodes.add((FuncFParamNode) temp);
                }
            }
        }
        return paramNodes;
    }

    public Token getIdent() {
        return ((Token)(nodes.get(1)));
    }
}
