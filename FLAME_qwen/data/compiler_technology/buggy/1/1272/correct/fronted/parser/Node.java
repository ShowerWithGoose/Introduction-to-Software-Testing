package fronted.parser;

import java.util.ArrayList;

public class Node {
    private int startLine;

    private int endLine;

    private SyntaxType type;

    private ArrayList<Node> children;
    //表示这个节点的子树

    public Node(int startLine, int endLine, SyntaxType type) {
        this.startLine = startLine;
        this.endLine = endLine;
        this.type = type;
        this.children = new ArrayList<>();
    }

    public int getEndLine() {
        return endLine;
    }

    public int getStartLine() {
        return startLine;
    }

    public SyntaxType getType() {
        return type;
    }

    public void addChild(Node node) {
        this.children.add(node);
    }

    public ArrayList<Node> getChildren() {
        return children;
    }

    @Override
    public String toString() {
        return "start : " + startLine + " end : " + endLine + " type : " + type.toString();
    }

    public String printType() {
        return this.type.toString();
    }
}
