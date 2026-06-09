package node;

import java.util.ArrayList;

public class NumberNode implements TreeNode {
    private Token token;

    public NumberNode(Token t) {
        this.token = t;
    }

    public void print() {

        token.print();
        System.out.println("<Number>");
    }

    public int getLine() {
        return token.getLine();
    }

    public TreeNode getNode() {
        return token;
    }
}
