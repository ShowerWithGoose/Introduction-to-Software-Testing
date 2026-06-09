import java.io.IOException;

public class BTypeNode extends ASTNode {
    private String s;

    public BTypeNode(String f){
        this.s = f;
    }

    public String getF() {
        return s;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitBType(this);
    }
}
