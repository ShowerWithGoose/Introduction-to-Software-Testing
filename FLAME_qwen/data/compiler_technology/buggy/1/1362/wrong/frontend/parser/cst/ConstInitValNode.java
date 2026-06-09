package frontend.parser.cst;

import java.util.ArrayList;

public class ConstInitValNode extends CSTNode {
    private ConstExpNode constExpNode = null;
    private final ArrayList<ConstInitValNode> constInitValNodes = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof ConstExpNode) {
            constExpNode = (ConstExpNode) node;
        } else if (node instanceof ConstInitValNode) {
            constInitValNodes.add((ConstInitValNode) node);
        }
    }

}
