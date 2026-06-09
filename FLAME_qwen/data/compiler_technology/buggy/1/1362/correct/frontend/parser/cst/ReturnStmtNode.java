package frontend.parser.cst;

public class ReturnStmtNode extends CSTNode {
    private ExpNode exp = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof ExpNode) {
            exp = (ExpNode) node;
        }
    }
}
