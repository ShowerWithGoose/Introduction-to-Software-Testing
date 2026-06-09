import java.io.IOException;

public class LOrExpNode extends ASTNode{
    private LAndExpNode lAndExpNode;
    private LOrExpNode lOrExpNode;

    public LOrExpNode(LOrExpNode lOrExpNode, LAndExpNode lAndExpNode){
        this.lAndExpNode = lAndExpNode;
        this.lOrExpNode = lOrExpNode;
    }

    public LAndExpNode getlAndExpNode() {
        return lAndExpNode;
    }

    public LOrExpNode getlOrExpNode() {
        return lOrExpNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitLOrExp(this);
    }
}
