package frontend.parser.cst;

public class InStmtNode extends CSTNode {
    private LValNode lVal = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof LValNode) {
            lVal = (LValNode) node;
        }
    }
}
