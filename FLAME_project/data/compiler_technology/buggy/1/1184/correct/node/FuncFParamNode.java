package node;

import Symbol.SignalType;

import java.util.ArrayList;

public class FuncFParamNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public FuncFParamNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<FuncFParam>");
    }


    public int getType() {
        BTypeNode typeNode = (BTypeNode) (nodes.get(0));
        Token token = (Token) (typeNode.getNode());
        if (token.getTokenType().equals(TokenType.CHARTK) && nodes.size() > 2) {
            return 2;
        } else if (token.getTokenType().equals(TokenType.INTTK) && nodes.size() > 2) {
            return 1;
        } else {
            return 0;
        }
    }

    public SignalType getSignalType() {
        BTypeNode typeNode = (BTypeNode) (nodes.get(0));
        Token token = (Token) (typeNode.getNode());
        if (token.getTokenType().equals(TokenType.CHARTK) && nodes.size() > 2) {
            return SignalType.CharArray;
        } else if (token.getTokenType().equals(TokenType.INTTK) && nodes.size() > 2) {
            return SignalType.IntArray;
        } else if (token.getTokenType().equals(TokenType.INTTK)){
            return SignalType.Int;
        } else {
            return SignalType.Char;
        }
    }
    public Token getIdent() {
        return ((Token) (nodes.get(1)));
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }
}
