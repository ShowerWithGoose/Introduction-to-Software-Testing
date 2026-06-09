package frontend.parser.cst;

import java.util.ArrayList;

public class ForLoopStmtNode extends CSTNode {
    private final ArrayList<CondNode> cond = new ArrayList<>();
    private final ArrayList<ForStmtNode> stmts = new ArrayList<>();
    private StmtNode stmtNode = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof CondNode) {
            cond.add((CondNode) node);
        } else if (node instanceof ForStmtNode) {
            stmts.add((ForStmtNode) node);
        } else if (node instanceof StmtNode) {
            stmtNode = (StmtNode) node;
        }
    }
}
