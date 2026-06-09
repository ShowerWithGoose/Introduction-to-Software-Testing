import java.io.IOException;
import java.util.List;

public class FuncFParamsNode extends ASTNode {
    private List<FuncFParamNode> funcFParamNodes;

    public FuncFParamsNode(List<FuncFParamNode> funcFParamNodes){
        this.funcFParamNodes = funcFParamNodes;
    }

    public List<FuncFParamNode> getFuncFParamNodes() {
        return funcFParamNodes;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitFuncFParams(this);
    }
}
