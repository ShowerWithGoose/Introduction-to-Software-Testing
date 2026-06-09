import java.io.IOException;

public class FuncFParamNode extends ASTNode {
    private BTypeNode bTypeNode;
    private String ident;

    private int n;

    public FuncFParamNode(BTypeNode bTypeNode, String s, int n){
        this.bTypeNode = bTypeNode;
        this.ident = s;
        this.n = n;
    }

    public String getIdent() {
        return ident;
    }

    public BTypeNode getbTypeNode() {
        return bTypeNode;
    }

    public int getN() {
        return n;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitFuncFParam(this);
    }
}
