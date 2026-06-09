import java.io.IOException;

public class LValNode extends ASTNode{
    private String ident;
    private ExpNode expNode;

    public LValNode(String ident, ExpNode expNode){
        this.expNode = expNode;
        this.ident = ident;
    }

    public ExpNode getExpNode() {
        return expNode;
    }

    public String getIdent() {
        return ident;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitLVal(this);
    }
}
