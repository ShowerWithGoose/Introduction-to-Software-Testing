package frontend.parser.cst;

public class RootNode extends CSTNode {
    
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (CSTNode node : children) {
            sb.append(node).append("\n");
        }
        return sb.toString();
    }
}
