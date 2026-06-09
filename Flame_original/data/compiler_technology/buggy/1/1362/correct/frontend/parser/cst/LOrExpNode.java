package frontend.parser.cst;

import java.util.ArrayList;

public class LOrExpNode extends CSTNode {
    private final ArrayList<LAndExpNode> lAndExps = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof LAndExpNode) {
            lAndExps.add((LAndExpNode) node);
        }
    }
}
