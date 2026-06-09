package frontend.parser.cst;

import java.util.ArrayList;

public class AddExpNode extends CSTNode {
    private final ArrayList<MulExpNode> mulExpNodes = new ArrayList<>();
    private final ArrayList<TokenNode> addOps = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof MulExpNode) {
            mulExpNodes.add((MulExpNode) node);
        } else if (node instanceof TokenNode) {
            addOps.add((TokenNode) node);
        }
    }
}
