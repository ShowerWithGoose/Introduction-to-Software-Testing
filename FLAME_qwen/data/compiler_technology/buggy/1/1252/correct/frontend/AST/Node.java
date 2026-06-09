package frontend.AST;

import java.util.ArrayList;

public class Node {
    protected int startLineNum;
    protected int endLineNum;
    protected SyntaxVarType type;
    protected ArrayList<Node> childNodes;

    public Node(int startLineNum, int endLineNum, SyntaxVarType type, ArrayList<Node> childNodes) {
        this.startLineNum = startLineNum;
        this.endLineNum = endLineNum;
        this.type = type;
        this.childNodes = childNodes;
    }

    public int getStartLineNum() {
        return this.startLineNum;
    }

    public int getEndLineNum() {
        return this.endLineNum;
    }

    public SyntaxVarType getType() {
        return this.type;
    }

    public ArrayList<Node> getChildNodes() {
        return this.childNodes;
    }

}
