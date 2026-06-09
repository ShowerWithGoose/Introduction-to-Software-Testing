package frontend.parser.cst;

public class UnaryExpNode extends CSTNode {
    private PrimaryExpNode primaryExpNode = null;
    private UnaryOpNode unaryOpNode = null;
    private UnaryExpNode unaryExpNode = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof PrimaryExpNode) {
            primaryExpNode = (PrimaryExpNode) node;
        } else if (node instanceof UnaryOpNode) {
            unaryOpNode = (UnaryOpNode) node;
        } else if (node instanceof UnaryExpNode) {
            unaryExpNode = (UnaryExpNode) node;
        }
    }
}
