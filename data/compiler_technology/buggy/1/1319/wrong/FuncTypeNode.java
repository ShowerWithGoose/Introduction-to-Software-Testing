import java.io.IOException;

public class FuncTypeNode extends ASTNode {
    private String type;

    public FuncTypeNode (String type){
        this.type = type;
    }

    public String getType() {
        return type;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitFuncType(this);
    }
}
