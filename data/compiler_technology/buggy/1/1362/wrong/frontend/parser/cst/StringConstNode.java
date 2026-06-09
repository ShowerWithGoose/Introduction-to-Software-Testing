package frontend.parser.cst;

public class StringConstNode extends CSTNode {
    private String value;

    public StringConstNode() {
        this.value  = "";
    }

    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof TokenNode) {
            this.value = ((TokenNode) node).getContent();
        }
    }
    
    public String getValue() {
        return value;
    }
}
