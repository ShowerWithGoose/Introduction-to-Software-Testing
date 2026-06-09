package parser_part.block;

import parser_part.Node;
import parser_part.declaration.Decl;
import parser_part.statement.Stmt;

public class BlockItem implements Node {
    private BlockItemComponent blockItemComponent;

    public BlockItem(BlockItemComponent blockItemComponent) {
        this.blockItemComponent = blockItemComponent;
    }

    @Override
    public String toString() {
        return blockItemComponent.toString();
    }

    public BlockItemComponent getBlockItemComponent() {
        return blockItemComponent;
    }

    public int checkReturn() {
        if (blockItemComponent instanceof Stmt) {
            return ((Stmt) blockItemComponent).checkReturn();
        } else {
            return -1;
        }
    }
}
