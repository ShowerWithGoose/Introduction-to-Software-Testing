package node;

import java.util.ArrayList;

public class BTypeNode implements TreeNode{
    private Token token;

    public BTypeNode(Token token) {
        this.token = token;
    }

    @Override
    public void print() {

        token.print();
        //System.out.println("<BType>");
    }

    public int getLine() {
        return token.getLine();
    }

    public TreeNode getNode() {
        return token;
    }
}
