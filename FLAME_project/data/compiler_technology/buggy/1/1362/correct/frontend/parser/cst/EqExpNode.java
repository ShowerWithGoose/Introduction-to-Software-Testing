package frontend.parser.cst;

import java.util.ArrayList;

public class EqExpNode extends CSTNode {
    private final ArrayList<RelExpNode> relExpNodes = new ArrayList<>();
    private final ArrayList<TokenNode> tokens = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof RelExpNode) {
            relExpNodes.add((RelExpNode) node);
        } else if (node instanceof TokenNode) {
            tokens.add((TokenNode) node);
        }
    }
}
