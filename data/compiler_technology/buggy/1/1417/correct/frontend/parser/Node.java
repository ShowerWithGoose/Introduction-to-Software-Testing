package frontend.parser;

import java.util.ArrayList;

// 语法树节点
public class Node {
    private int starttLine;
    private int endLine;
    // 对于非终结符，name为"<...>"
    // 对于终结符，name即为其自身value
    // 对于自定义非终结符，name为""
    private String name;
    // 子节点
    private ArrayList<Node> nodes;

    public Node(int starttLine, int endLine, String name, ArrayList<Node> nodes) {
        this.starttLine = starttLine;
        this.endLine = endLine;
        this.name = name;
        this.nodes = nodes;
    }

    public int getStarttLine() {
        return this.starttLine;
    }

    public int getEndLine() {
        return this.endLine;
    }

    public ArrayList<Node> getNodes(){
        return this.nodes;
    }

    public String getName(){
        return this.name;
    }
}
