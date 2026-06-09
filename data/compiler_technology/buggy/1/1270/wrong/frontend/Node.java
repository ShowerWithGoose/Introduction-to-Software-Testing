package frontend;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Node {
    String type;
    String value;
    List<Node> children;
    public Node(String type, String value){
        this.type = type;
        this.value = value;
        this.children = new ArrayList<>();
    }
    public Node(String value){
        this.value = value;
        this.children = new ArrayList<>();
    }
    public Node(){
        this.children = new ArrayList<>();
    }
    public void addChild(Node child){
        children.add(child);
    }
    public void printTree(Node root, PrintWriter parseOutput) {
        if (root != null) {
            printNode(root, parseOutput);
        }
    }
    private void printNode(Node node, PrintWriter parseOutput) {
        for (Node child : node.children) {
            printNode(child, parseOutput);
        }
        if (node.type != null) {
            parseOutput.println(node.type + " " + node.value);
        } else if(node.value != null){
            parseOutput.println(node.value);
        }
    }
    /*public void printTree(Node root) {
        if (root != null) {
            System.out.println(root.value);
            printNode(root, 1);
        }
    }

    private void printNode(Node node, int level) {
        for (Node child : node.children) {
            String indent = "  ".repeat(level);
            if(child.type != null)
                System.out.println(indent + child.type +  " " + child.value); // 输出子节点的值
            else
                System.out.println(indent + child.value);
            printNode(child, level + 1);
        }
    }*/



}
