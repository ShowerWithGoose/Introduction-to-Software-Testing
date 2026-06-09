import java.io.IOException;

public class MulExpNode extends ASTNode{
    private UnaryExpNode unaryExpNode;
    private MulExpNode mulExpNode;
    private char ch;

    public MulExpNode(UnaryExpNode unaryExpNode, MulExpNode mulExpNode, char ch){
        this.mulExpNode = mulExpNode;
        this.unaryExpNode = unaryExpNode;
        this.ch = ch;
    }

    public MulExpNode getMulExpNode() {
        return mulExpNode;
    }

    public UnaryExpNode getUnaryExpNode() {
        return unaryExpNode;
    }

    public char getCh() {
        return ch;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitMulExp(this);
    }
}
