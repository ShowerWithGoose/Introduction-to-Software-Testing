import java.io.IOException;
import java.util.List;

public class FuncDefNode extends ASTNode {
    private FuncTypeNode funcType;
    private String identifier;
    private FuncFParamsNode params;
    private BlockNode block;

    public FuncDefNode(FuncTypeNode funcType, String identifier, FuncFParamsNode params, BlockNode block) {
        this.funcType = funcType;
        this.identifier = identifier;
        this.params = params;
        this.block = block;
    }

    public BlockNode getBlock() {
        return block;
    }

    public FuncFParamsNode getParams() {
        return params;
    }

    public FuncTypeNode getFuncType() {
        return funcType;
    }

    public String getIdentifier() {
        return identifier;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitFuncDef(this);
    }
}