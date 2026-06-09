package frontend;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class Node {
    private String name;
    private ArrayList<Node> children;

    public Node(String name) {
        this.name = name;
        children = new ArrayList<>();
    }

    public void addChild(Node node) {
        children.add(node);
    }

    public String getName() {
        return name;
    }
    public ArrayList<Node> getChildren() {
        return children;
    }
}
