import java.io.IOException;
import java.util.List;

public class FuncRParamsNode extends ASTNode{
    private List<ExpNode> expList;

    public FuncRParamsNode(List<ExpNode> expList){
        this.expList = expList;
    }

    public List<ExpNode> getExpList() {
        return expList;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitFuncRParams(this);
    }
}