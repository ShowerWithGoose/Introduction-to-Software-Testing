import java.io.IOException;
import java.util.List;

public class BlockNode extends ASTNode
{
    List<BlockItemNode> blockItems;

    public BlockNode(List<BlockItemNode> blockItems) {
        this.blockItems = blockItems;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitBlock(this);
    }
}
