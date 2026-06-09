package node;

import com.sun.source.tree.Tree;

import java.util.ArrayList;

public class FuncTypeNode implements TreeNode {
    private Token token;

    public FuncTypeNode(Token token) {
        this.token = token;
    }

    @Override
    public void print() {
        token.print();
        System.out.println("<FuncType>");
    }

    public int getLine() {
        return token.getLine();
    }

    public TreeNode getNode() {
        return token;
    }
}
