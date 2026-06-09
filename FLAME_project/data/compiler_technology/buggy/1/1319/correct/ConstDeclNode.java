import java.io.IOException;
import java.util.List;

public class ConstDeclNode extends ASTNode {
    private BTypeNode btype;
    private List<ConstDefNode> constdefs;

    public ConstDeclNode(BTypeNode btype, List<ConstDefNode> constdefs){
        this.btype = btype;
        this.constdefs = constdefs;
    }

    public BTypeNode getBtype() {
        return btype;
    }

    public List<ConstDefNode> getConstdefs() {
        return constdefs;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitConstDecl(this);
    }
}
