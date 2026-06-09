package frontend.parser.cst;

public class AssignStmtNode extends CSTNode {
    private LValNode lValNode;
    private ExpNode expNode;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof LValNode) {
            lValNode = (LValNode) node;
        } else if (node instanceof ExpNode) {
            expNode = (ExpNode) node;
        }
    }
}
