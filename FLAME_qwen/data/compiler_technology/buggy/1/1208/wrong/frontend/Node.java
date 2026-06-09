package frontend;

import java.util.ArrayList;
import java.util.List;

public class Node {
    protected SyntaxType name;
    protected String content;
    protected boolean isEnd;
    protected ArrayList<Node> childNodes;
    protected Node parentNode;
    protected Token token;
    protected Error error;
    protected StringBuilder sb = new StringBuilder();

    public Node(SyntaxType name, Token token) {
        this.name = name;
        this.isEnd = false;
        this.childNodes = new ArrayList<>();
        this.token = token;
    }

    public Node(String content, Token token) {
        this.content = content;
        this.isEnd = true;
        this.token = token;
    }

    public void addChildNode(Node node) {
        this.childNodes.add(node);
    }

    public void addChildNodes(ArrayList<Node> childNodes) {
        this.childNodes = childNodes;
    }

    public List<Node> getChildNodes() {
        return childNodes;
    }

    public String toString() {
        if (isEnd) {
            return token.getType().toString() + " "+ content + '\n';
        } else {
            if (name == SyntaxType.BlockItem || name == SyntaxType.BType) {
                return "";
            }
            return name.toString() + '\n';
        }
    }

    public String getSb() {
        return sb.toString();
    }

    public void postOrder(Node node) {
        if (node == null) {
            return;
        }
        if (node.childNodes != null && !node.childNodes.isEmpty()) {
            for (Node n : node.childNodes) {
                postOrder(n);
            }
        }
        sb.append(node.toString());
    }

    public Token getToken() {
        return token;
    }
}
