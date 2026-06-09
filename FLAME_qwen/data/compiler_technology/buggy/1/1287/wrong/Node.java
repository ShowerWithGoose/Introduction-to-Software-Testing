import java.util.ArrayList;

public class Node {
    private ArrayList<Node> nodeTree = new ArrayList<>();
    private ArrayList<Node> nodePost = new ArrayList<>();

    public void addNode(Node node) {
        nodeTree.add(node);
    }

    public void removeNode() {
        int n = nodeTree.size();
        nodeTree.remove(n - 1);
    }

    public String toString() {
        return " ";
    }
    public void postrav(Node node) {
        if (node.nodeTree.isEmpty()) {
            nodePost.add(node);
            return;
        }
        for (Node n : node.nodeTree) {
            postrav(n);
        }
        nodePost.add(node);
    }

    public ArrayList<Node> getNodePost() {
        return nodePost;
    }
}
