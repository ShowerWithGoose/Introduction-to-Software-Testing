package frontend.parser.cst;

import java.util.ArrayList;

public class ConditionStmtNode extends CSTNode {
    private CondNode cond;
    private final ArrayList<StmtNode> stmtNodes = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof CondNode) {
            cond = (CondNode) node;
        } else if (node instanceof StmtNode) {
            stmtNodes.add((StmtNode) node);
        }
    }
}
