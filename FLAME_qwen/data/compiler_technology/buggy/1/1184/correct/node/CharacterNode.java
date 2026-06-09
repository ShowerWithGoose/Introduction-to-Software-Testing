package node;

public class CharacterNode implements TreeNode {
    private Token token;

    public CharacterNode(Token t) {
        this.token = t;
    }

    public void print() {

        token.print();
        System.out.println("<Character>");
    }

    public int getLine() {
        return token.getLine();
    }

    public TreeNode getNode() {
        return token;
    }
}
