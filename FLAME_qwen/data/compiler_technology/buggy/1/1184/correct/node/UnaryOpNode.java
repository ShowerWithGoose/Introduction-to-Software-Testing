package node;

import java.util.ArrayList;

public class UnaryOpNode implements TreeNode {
    private Token token;

    public UnaryOpNode(Token t) {
        this.token = t;
    }

    public void print() {

        token.print();
        System.out.println("<UnaryOp>");
    }

    public int getLine() {
        return token.getLine();
    }

    public TreeNode getNode() {
        return token;
    }
}
