package frontend.Parser.Statement;

import frontend.Parser.ASTNode;

public class BlockItem implements ASTNode {
    private BlockItemEle blockItemEle;

    public BlockItem(BlockItemEle blockItemEle) {
        this.blockItemEle = blockItemEle;
    }

    @Override
    public String printString() {
        return blockItemEle.printString();
    }
}
