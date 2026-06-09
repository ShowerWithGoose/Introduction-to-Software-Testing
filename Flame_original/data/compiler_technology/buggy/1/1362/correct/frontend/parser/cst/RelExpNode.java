package frontend.parser.cst;

import java.util.ArrayList;

public class RelExpNode extends CSTNode {
    private final ArrayList<AddExpNode> addExpNodes = new ArrayList<>();
    private final ArrayList<TokenNode> relOps = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof AddExpNode) {
            addExpNodes.add((AddExpNode) node);
        } else if (node instanceof TokenNode) {
            relOps.add((TokenNode) node);
        }
    }
}
