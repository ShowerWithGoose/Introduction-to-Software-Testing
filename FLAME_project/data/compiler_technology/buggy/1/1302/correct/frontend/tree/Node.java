package frontend.tree;

import java.util.ArrayList;
import java.util.List;

public class Node {
    protected ArrayList<Node> children;
    protected int beginLine;
    protected int endLine;

    public Node() {
        this.children = new ArrayList<Node>();
    }

    public Node(int beginLine, int endLine) {
        this.children = new ArrayList<Node>();
        this.beginLine = beginLine;
        this.endLine = endLine;
    }

    public void addChild(Node child) {
        children.add(child);
    }

    public void setBeginLine(int beginLine) {
        this.beginLine = beginLine;
    }

    public int getBeginLine() {
        return beginLine;
    }

    public void setEndLine(int endLine) {
        this.endLine = endLine;
    }

    public int getEndLine() {
        return endLine;
    }

    public List<Node> getChildren() {
        return children;
    }

    public void removeChild(Node child) {
        children.remove(child);
    }

    public void semanticAnalysis() {
        for (Node child : children) {
            child.semanticAnalysis();
        }
    }

    public Node getFirstLeaf() {
        return null;
    }
}
