import java.io.IOException;

public class CondNode extends ASTNode{
    private LOrExpNode lOrExpNode;

    public CondNode(LOrExpNode lOrExpNode){
        this.lOrExpNode = lOrExpNode;
    }

    public LOrExpNode getlOrExpNode() {
        return lOrExpNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitCond(this);
    }
}
