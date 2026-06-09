package frontend.SyntaxTree;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class SyntaxTreeNode {
    private String type; // 节点类型（Token名称或语法节点名称）
    private String value; // Token 的值（仅当为终结符时使用）

    private List<SyntaxTreeNode> children; // 子节点列表

    // 用于创建非终结符节点（例如 <VarDef>）
    public SyntaxTreeNode(String type) {
        this.type = type;
        this.children = new ArrayList<>();
    }

    // 用于创建终结符节点（例如 INT、IDENFR）
    public SyntaxTreeNode(String type, String value) {
        this.type = type;
        this.value = value;
        this.children = new ArrayList<>();
    }

    public String getType() {
        return type;
    }

    public List<SyntaxTreeNode> getChildren() {
        return children;
    }

    public void addChild(SyntaxTreeNode child) {
        this.children.add(child);
    }

    public String getValue() {
        return value;
    }

    public void traverse(BufferedWriter writer) throws IOException {
        // 遍历每个子节点
        for (SyntaxTreeNode child : children) {
            // 如果是词法单元（叶子节点），先输出词法单元
            if (child.getChildren().isEmpty()) {
                writer.write(child.getType() + " " + child.getValue());
                writer.newLine(); // 换行
            } else {
                // 递归遍历子节点
                child.traverse(writer);

                // 如果是指定的语法节点（<BlockItem>, <Decl>, <BType>），不输出
                if (!child.getType().equals("BlockItem") && !child.getType().equals("Decl") && !child.getType().equals("BType")) {
                    writer.write("<" + child.getType() + ">");
                    writer.newLine(); // 换行
                }
            }
        }
    }


}
