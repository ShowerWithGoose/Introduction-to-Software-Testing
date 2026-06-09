package frontend.parser.cst;

public class CharacterNode extends CSTNode {
    private char content;
    
    public CharacterNode() {
        this.content = '\0';
    }
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof TokenNode) {
            String content = ((TokenNode) node).getContent();
            this.content = content.charAt(0);
        }
    }
}
