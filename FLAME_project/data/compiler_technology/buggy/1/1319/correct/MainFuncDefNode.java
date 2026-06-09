import java.io.IOException;
import java.util.ArrayList;

public class MainFuncDefNode extends FuncDefNode {
    public MainFuncDefNode(BlockNode block) {
        super(new FuncTypeNode("int"), "main", null, block);
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitMainFuncDef(this);
    }
}
