package frontend.parser.cst;

import java.util.ArrayList;

public class InitValNode extends CSTNode {
    private ExpNode exp = null;
    private final ArrayList<InitValNode> initValList = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof ExpNode) {
            exp = (ExpNode) node;
        } else if (node instanceof InitValNode) {
            initValList.add((InitValNode) node);
        }
    }
}
