import java.io.IOException;

public class ConstDefNode extends ASTNode{
    private String ident;
    private ConstExpNode constexp;
    private ConstInitValNode constintval;

    public ConstDefNode(String ident, ConstExpNode constexp, ConstInitValNode constInitValNode){
        this.constexp = constexp;
        this.constintval = constInitValNode;
        this.ident = ident;
    }

    public ConstExpNode getConstexp() {
        return constexp;
    }

    public ConstInitValNode getConstintval() {
        return constintval;
    }

    public String getIdent() {
        return ident;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitConstDef(this);
    }
}
