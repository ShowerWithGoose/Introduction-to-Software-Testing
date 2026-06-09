package frontend;
import java.util.ArrayList;
import java.util.List;

public class TreeNode {
    String type; // 节点类型，例如 <Stmt>
    List<TreeNode> children; // 子节点列表
    boolean isLeaf;
    Token token;

    public TreeNode(String type , boolean isLeaf , Token token) {
        this.type = type;
        this.children = new ArrayList<>();
        this.isLeaf = isLeaf;
        this.token = token;
    }

    public void addChild(TreeNode child) {
        children.add(child);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        int k = 0;
        if (isLeaf) {
            sb.append(token.toString());
            return sb.toString();
        }
        for (TreeNode child : children) {
            sb.append(child.toString());
            /*if (type.equals("<AddExp>") && child.type.equals("<MulExp>") ||
                    type.equals("<MulExp>") && child.type.equals("<UnaryExp>") ||
                    type.equals("<RelExp>") && child.type.equals("<AddExp>") ||
                    type.equals("<EqExp>") && child.type.equals("<RelExp>") ||
                    type.equals("<LAndExp>") && child.type.equals("<EqExp>") ||
                    type.equals("<LOrExp>") && child.type.equals("<LAndExp>")) {
                sb.append(type).append('\n');
                k = 1;
            } */
        }
        if (!type.equals("<BlockItem>") && !type.equals("<Decl>") && !type.equals("<BType>") && k == 0) {
            sb.append(type).append('\n');
        }
        return sb.toString();
    }
}

