import java.io.IOException;
import java.util.List;

public class UnaryExpNode extends ASTNode{

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return null;
    }
}

class PrimaryUExp extends UnaryExpNode{
    private PrimaryExpNode primaryExpNode;

    public PrimaryUExp(PrimaryExpNode primaryExpNode){
        this.primaryExpNode = primaryExpNode;
    }

    public PrimaryExpNode getPrimaryExpNode() {
        return primaryExpNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitPrimaryUExp(this);
    }
}

class IdentUExp extends UnaryExpNode{
    private String ident;
    private FuncRParamsNode funcRParams;

    public IdentUExp(String ident, FuncRParamsNode funcRParams){
        this.funcRParams = funcRParams;
        this.ident = ident;
    }

    public String getIdent() {
        return ident;
    }

    public FuncRParamsNode getFuncRParams() {
        return funcRParams;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitIdentUExp(this);
    }
}

class UUExp extends UnaryExpNode{
    private UnaryOpNode unaryOpNode;
    private UnaryExpNode unaryExpNode;

    public UUExp(UnaryOpNode unaryOpNode, UnaryExpNode unaryExpNode){
        this.unaryExpNode = unaryExpNode;
        this.unaryOpNode = unaryOpNode;
    }

    public UnaryExpNode getUnaryExpNode() {
        return unaryExpNode;
    }

    public UnaryOpNode getUnaryOpNode() {
        return unaryOpNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitUUExp(this);
    }
}
