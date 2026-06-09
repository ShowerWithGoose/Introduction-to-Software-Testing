package node;

import token.Token;
import token.Type;

import java.util.ArrayList;
import java.util.List;

public class Node {
    public NodeType type;
    private final List<Node> children = new ArrayList<>();
    private int line;
    private String value = "";

    public Node(NodeType type) {
        this.type = type;
        this.setValueN();
    }

    public Node(Token token) {
        this.value = token.toString();
        this.type = NodeType.Terminal;
        this.children.clear();
    }

    public void addChild(Node child) {
        children.add(child);
    }

    public void deleteChild() {
        children.remove(children.size() - 1);
    }
    public void setValueN() {
        this.value = (type == NodeType.BlockItem || type == NodeType.Decl || type == NodeType.BType)
                ? "" : "<" + type.toString() + ">";
    }

    public String getValue() {
        return value;
    }

    public Node getChild(int index) {
        if (index < 0 || index >= children.size()) {
            return null;
        }
        return children.get(index);
    }

    public List<Node> getChildren() {
        return children;
    }

    public int getLine() {
        return line;
    }

    @Override
    public String toString() {
        return this.value;
    }

 }
