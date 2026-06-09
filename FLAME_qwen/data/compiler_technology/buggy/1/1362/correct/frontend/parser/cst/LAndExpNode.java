package frontend.parser.cst;

import java.util.ArrayList;

public class LAndExpNode extends CSTNode {
    private final ArrayList<EqExpNode> eqExpNodes = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof EqExpNode) {
            eqExpNodes.add((EqExpNode) node);
        }
    }
}
