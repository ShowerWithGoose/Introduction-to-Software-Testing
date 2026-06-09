package Frontend;

import java.util.ArrayList;

public class TreeNode {
    private ParsType parsType;
    private LexType lexType;
    private String token;
    private ArrayList<TreeNode> children = new ArrayList<>();

    public TreeNode(ParsType type, ArrayList<TreeNode> children){
        this.parsType = type;
        this.children = children;
    }

    public TreeNode(LexType type,String token) {
        this.lexType = type;
        this.token = token;
    }

    public void addNode(TreeNode leaf) {
        children.add(leaf);
    }

    public ParsType getParsType() {
        return parsType;
    }
}
