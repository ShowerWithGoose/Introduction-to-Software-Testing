import java.io.IOException;

public class ExpNode extends ASTNode{
    private AddExpNode addExp;

    public ExpNode(AddExpNode addExp){
        this.addExp = addExp;
    }

    public AddExpNode getAddExp() {
        return addExp;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitExp(this);
    }
}
