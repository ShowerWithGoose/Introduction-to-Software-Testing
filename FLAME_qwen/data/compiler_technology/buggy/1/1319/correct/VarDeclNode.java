import java.io.IOException;
import java.util.List;

public class VarDeclNode extends ASTNode {
    private BTypeNode bTypeNode;
    private List<VarDefNode> varDefNodes;

    public VarDeclNode(BTypeNode bTypeNode, List<VarDefNode> varDefNodes){
        this.bTypeNode =bTypeNode;
        this.varDefNodes = varDefNodes;
    }

    public BTypeNode getbTypeNode() {
        return bTypeNode;
    }

    public List<VarDefNode> getVarDefNodes() {
        return varDefNodes;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitVarDecl(this);
    }
}
