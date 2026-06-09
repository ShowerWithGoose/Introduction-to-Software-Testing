package frontend.parser.cst;

import java.util.ArrayList;

public class VarDefNode extends CSTNode {
    private TokenNode ident;
    private final ArrayList<ConstExpNode> constExpList = new ArrayList<>();
    private InitValNode initVal = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (children.size() == 1) {
            ident = (TokenNode) node;
        } else if (node instanceof ConstExpNode) {
            constExpList.add((ConstExpNode) node);
        } else if (node instanceof InitValNode) {
            initVal = (InitValNode) node;
        }
    }
}
