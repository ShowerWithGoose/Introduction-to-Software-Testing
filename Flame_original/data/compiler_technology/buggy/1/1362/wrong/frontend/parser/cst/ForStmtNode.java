package frontend.parser.cst;

public class ForStmtNode extends CSTNode {
    private LValNode lValNode = null;
    private ExpNode expNode = null;
    
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
