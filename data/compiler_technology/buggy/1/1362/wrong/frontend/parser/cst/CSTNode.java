package frontend.parser.cst;

import java.util.ArrayList;

public class CSTNode {
    protected final ArrayList<CSTNode> children = new ArrayList<>();
    
    public void addChild(CSTNode node) {
        children.add(node);
    }
    
    public ArrayList<CSTNode> getChildren() {
        return this.children;
    }
    
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (CSTNode node : children) {
            sb.append(node).append(" ");
        }
        return sb.substring(0, sb.length() - 1);
    }
    
}
