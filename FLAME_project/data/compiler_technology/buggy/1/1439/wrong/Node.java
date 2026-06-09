import java.util.ArrayList;
import java.util.List;

public class Node {
    String type; // 节点类型，如 <Stmt>、<Exp> 等
    String value; // 对于终结符节点，存储实际的值（如 "int", "main" 等）
    List<Node> children; // 子节点列表

    public Node(String type) {
        this.type = type;
        this.value = null;
        this.children = new ArrayList<>();
    }

    public Node(String type, String value) {
        this.type = type;
        this.value = value;
        this.children = new ArrayList<>();
    }

    public void addChild(Node child) {
        children.add(child);
    }
}
