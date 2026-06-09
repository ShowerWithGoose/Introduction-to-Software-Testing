import java.io.IOException;

public class LAndExpNode extends ASTNode{
    private EqExpNode eqExpNode;
    private LAndExpNode lAndExpNode;

    public LAndExpNode(EqExpNode eqExpNode, LAndExpNode lAndExpNode){
        this.eqExpNode = eqExpNode;
        this.lAndExpNode = lAndExpNode;
    }

    public EqExpNode getEqExpNode() {
        return eqExpNode;
    }

    public LAndExpNode getlAndExpNode() {
        return lAndExpNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitLAndExp(this);
    }
}
