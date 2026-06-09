import java.io.IOException;

public class AddExpNode extends ASTNode
{
    private MulExpNode mulExp;
    private AddExpNode addExpNode;
    private char ch;

    public AddExpNode(AddExpNode addExpNode, MulExpNode mulExpNode, char ch){
        this.addExpNode = addExpNode;
        this.mulExp = mulExpNode;
        this.ch = ch;
    }

    public AddExpNode getAddExpNode() {
        return addExpNode;
    }

    public char getCh() {
        return ch;
    }

    public MulExpNode getMulExp() {
        return mulExp;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitAddExp(this);
    }
}
