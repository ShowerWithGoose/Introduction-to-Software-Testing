package frontend.parser.cst;

import java.util.ArrayList;

public class ConstDefNode extends CSTNode {
    private TokenNode ident;
    private final ArrayList<ConstExpNode> constExps = new ArrayList<>();
    private ConstInitValNode constInitVal;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (children.size() == 1) {
            ident = (TokenNode) node;
        } else if (node instanceof ConstInitValNode) {
            constInitVal = (ConstInitValNode) node;
        } else if (node instanceof ConstExpNode) {
            constExps.add((ConstExpNode) node);
        }
    }
}
