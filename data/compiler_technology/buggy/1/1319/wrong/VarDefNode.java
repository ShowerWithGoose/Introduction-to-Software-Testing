import java.io.IOException;

public class VarDefNode extends ASTNode {
    private String ident;
    private ConstExpNode constExpNode;
    private InitValNode initValNode;

    public VarDefNode(String ident, ConstExpNode constDefNode, InitValNode initValNode){
        this.constExpNode = constDefNode;
        this.ident = ident;
        this.initValNode = initValNode;
    }

    public String getIdent() {
        return ident;
    }

    public ConstExpNode getConstExpNode() {
        return constExpNode;
    }

    public InitValNode getInitValNode() {
        return initValNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitVarDef(this);
    }
}
