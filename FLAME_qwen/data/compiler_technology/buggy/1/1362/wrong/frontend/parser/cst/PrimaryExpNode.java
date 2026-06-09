package frontend.parser.cst;

public class PrimaryExpNode extends CSTNode {
    private ExpNode expNode = null;
    private LValNode lValNode = null;
    private NumberNode numberNode = null;
    private CharacterNode characterNode = null;
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof ExpNode) {
            expNode = (ExpNode) node;
        } else if (node instanceof LValNode) {
            lValNode = (LValNode) node;
        } else if (node instanceof NumberNode) {
            numberNode = (NumberNode) node;
        } else if (node instanceof CharacterNode) {
            characterNode = (CharacterNode) node;
        }
    }
}
