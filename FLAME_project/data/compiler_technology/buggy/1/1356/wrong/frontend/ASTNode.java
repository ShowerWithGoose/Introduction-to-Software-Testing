package frontend;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ASTNode {
    public String value;
    public String type;
    public List<ASTNode> children;
    public int lineNum;

    //构造函数
    public ASTNode(String value) {
        this.value = value;
        this.type = "";
        this.lineNum = -1;
        this.children = new ArrayList<>();
    }
    public ASTNode(String value, int lineNum) {
        this.value = value;
        this.type = "";
        this.lineNum = lineNum;
        this.children = new ArrayList<>();
    }
    public ASTNode(String value, String type, int lineNum) {
        this.value = value;
        this.type = type;
        this.lineNum = lineNum;
        this.children = new ArrayList<>();
    }

    //添加子节点
    public void addChild(ASTNode node) {
        children.add(node);
    }

    public void traverseOutput(ASTNode node, PrintWriter output) {
        for (ASTNode child : children) {
            child.traverseOutput(child, output);
        }
        if (lineNum == -1) {
            output.println("<" + value + ">");
        } else {
            output.println(type + " " + value);
        }
    }
}
