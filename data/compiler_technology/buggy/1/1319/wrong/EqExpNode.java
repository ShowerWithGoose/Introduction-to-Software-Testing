import java.io.IOException;

public class EqExpNode extends ASTNode{
    private RelExpNode relExpNode;
    private EqExpNode eqExpNode;
    private String string;

    public EqExpNode(RelExpNode relExpNode, EqExpNode eqExpNode, String s){
        this.eqExpNode = eqExpNode;
        this.string = s;
        this.relExpNode = relExpNode;
    }

    public EqExpNode getEqExpNode() {
        return eqExpNode;
    }

    public RelExpNode getRelExpNode() {
        return relExpNode;
    }

    public String getString() {
        return string;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitEqExp(this);
    }
}
