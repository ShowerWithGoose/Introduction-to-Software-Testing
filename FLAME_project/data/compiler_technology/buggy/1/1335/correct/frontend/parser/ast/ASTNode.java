package frontend.parser.ast;

import frontend.lexer.Token;
import frontend.parser.SynComponent;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ASTNode {

    private SynComponent component;

    private Token token;
    private ArrayList<ASTNode> childNodes;
    private ASTNode fatherNode;
    private boolean isRoot;
    private boolean isLeaf;

    public ASTNode(SynComponent component,boolean isRoot,Token token,boolean isLeaf) {
        this.component = component;
        this.childNodes = new ArrayList<>();
        this.fatherNode = null;
        this.token = token;
        this.isRoot = isRoot;
        this.isLeaf = isLeaf;
    }

    public void addChild(ASTNode child) {
        childNodes.add(child);
        child.setFatherNode(this);
        updateLeafStatus();
      System.out.println("!"+child.toPrint(child));
    }

    public ArrayList<ASTNode> getChildren() {
        return childNodes;
    }

    public ASTNode getFatherNode() {
        return fatherNode;
    }

    private void setFatherNode(ASTNode father) {
        this.fatherNode = father;
    }

    public boolean isRoot() {
        return isRoot;
    }

    public void setRoot() {
        this.isRoot = true;
    }

    public boolean isLeaf() {
        return isLeaf;
    }

    private void updateLeafStatus() {
        this.isLeaf = childNodes.isEmpty();
    }

    public SynComponent getComponent() {
        return component;
    }

    public static void postOrderPrint(ASTNode node, BufferedWriter writer) throws IOException {
        if (node == null) return;

        // 首先递归遍历每个子节点
        for (ASTNode child : node.childNodes) {
            postOrderPrint(child, writer);
        }

        // 获取当前节点的值
        String output = toPrint(node);

        // 仅在output不为空时写入
        if (!output.isEmpty()) {
            System.out.println(output);
            writer.write(output);  // Use the toPrint method to get the string representation
            writer.newLine();  // Ensure each output is on a new line
        }
    }


    public static int postOrderPrint(ASTNode node) {
        if (node == null) return 0;

        // 首先递归遍历每个子节点
        for (ASTNode child : node.childNodes) {
            postOrderPrint(child);
        }
        String output = toPrint(node);

        // 仅在output不为空时写入
        if (!output.isEmpty()) {
            System.out.println(toPrint(node));
        }

        // 输出当前节点的值
        System.out.println(toPrint(node));
        return 0;
    }

    public static String toPrint(ASTNode node) {
        if (node == null) {
            return ""; // 处理空节点
        }

        if (node.token != null) {
            Token token = node.token;
            return token.getType() + " " + token.getTokenString();
        } else if (node.component != null) {
            return "<" + node.component.toString() + ">";
        } else {
            return ""; // 如果没有token和component，返回空字符串
        }
    }

}
