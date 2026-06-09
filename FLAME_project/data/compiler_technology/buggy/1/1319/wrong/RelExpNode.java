import java.io.IOException;

public class RelExpNode extends ASTNode{
    private AddExpNode addExpNode;
    private RelExpNode relExpNode;
    private String s;

    public RelExpNode(AddExpNode addExpNode, RelExpNode relExpNode, String s){
        this.addExpNode = addExpNode;
        this.s = s;
        this.relExpNode = relExpNode;
    }

    public RelExpNode getRelExpNode() {
        return relExpNode;
    }

    public AddExpNode getAddExpNode() {
        return addExpNode;
    }

    public String getS() {
        return s;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitRelExp(this);
    }
}
