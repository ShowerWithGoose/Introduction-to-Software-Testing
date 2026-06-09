package frontend.parser.cst;

import java.util.ArrayList;

public class FuncRParamsNode extends CSTNode {
    private final ArrayList<ExpNode> params = new ArrayList<>();

    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof ExpNode) {
            params.add((ExpNode) node);
        }
    }

    public ArrayList<ExpNode> getParams() {
        return params;
    }
}
