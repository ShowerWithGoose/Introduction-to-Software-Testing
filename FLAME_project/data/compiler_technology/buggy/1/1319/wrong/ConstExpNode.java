import java.io.IOException;

public class ConstExpNode extends ASTNode{
    private AddExpNode addExpNode;

    public ConstExpNode(AddExpNode addExpNode){
        this.addExpNode = addExpNode;
    }

    public AddExpNode getAddExpNode() {
        return addExpNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitConstExp(this);
    }
}
