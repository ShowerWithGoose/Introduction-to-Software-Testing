package frontend.parser.cst;

import java.util.ArrayList;

public class CalleeNode extends CSTNode {
    private TokenNode ident = null;
    private FuncRParamsNode params = null;
    private final ArrayList<ExpNode> arguments = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (children.size() == 1) {
            ident = (TokenNode) node;
        } else if (node instanceof FuncRParamsNode) {
            params = (FuncRParamsNode) node;
        }
    }
}
