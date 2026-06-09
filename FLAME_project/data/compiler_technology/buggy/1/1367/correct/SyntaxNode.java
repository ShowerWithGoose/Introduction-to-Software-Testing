import java.util.ArrayList;
import java.util.List;

class SyntaxNode {
    private String type; // 节点类型，例如 "ConstDecl"、"VarDecl" 等
    private List<SyntaxNode> children; // 子节点

    public SyntaxNode(String type) {
        this.type = type;
        this.children = new ArrayList<>();
    }

    public String getType() {
        if (type.contains(" ")) {
            String[] parts = type.split(" ");
            return parts[0];
        }
        else {
            return type;
        }
    }
    public String getName() {
        if (type.contains(" ")) {
            String[] parts = type.split(" ");
            return parts[1];
        }
        return null;
    }
    public List<SyntaxNode> getChildren() {
        return children;
    }

    public void addChild(SyntaxNode child) {
        children.add(child);
    }

    @Override
    public String toString() {
        return toString(0);
    }

    private String toString(int level) {
        StringBuilder sb = new StringBuilder();
        //sb.append("  ".repeat(level)).append(type).append("\n");
        if (children.isEmpty()) {
            sb.append(type).append("\n");
        } else {
            for (SyntaxNode child : children) {
                sb.append(child.toString(level + 1));
            }
            sb.append(type).append("\n");
        }
        return sb.toString();
    }
    public void printTree(SyntaxNode node, int level) {
        for (int i = 0; i < level; i++) {
            System.out.print("    "); // 每层缩进4个空格
        }
        System.out.println(node.type);
        for (SyntaxNode childeNode : node.children) {
            printTree(childeNode, level + 1);
        }
    }
}
