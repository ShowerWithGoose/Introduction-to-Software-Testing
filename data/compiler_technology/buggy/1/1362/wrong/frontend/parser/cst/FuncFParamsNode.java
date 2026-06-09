package frontend.parser.cst;

import java.util.ArrayList;

public class FuncFParamsNode extends CSTNode {
    private final ArrayList<FuncFParamNode> params = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof FuncFParamNode) {
            params.add((FuncFParamNode) node);
        }
    }
    
}
