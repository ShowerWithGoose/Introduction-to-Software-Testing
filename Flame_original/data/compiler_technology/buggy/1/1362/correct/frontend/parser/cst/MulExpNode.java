package frontend.parser.cst;

import java.util.ArrayList;

public class MulExpNode extends CSTNode {
    private final ArrayList<UnaryExpNode> unaryExpNodes = new ArrayList<>();
    private final ArrayList<TokenNode> mulOpNodes = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof UnaryExpNode) {
            unaryExpNodes.add((UnaryExpNode) node);
        } else if (node instanceof TokenNode) {
            mulOpNodes.add((TokenNode) node);
        }
    }
}
