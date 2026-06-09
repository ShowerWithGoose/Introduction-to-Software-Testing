package frontend.parser.cst;

import java.util.ArrayList;

public class BlockNode extends CSTNode {
    private final ArrayList<BlockItemNode> blockItems = new ArrayList<>();
    
    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof BlockItemNode) {
            blockItems.add((BlockItemNode) node);
        }
    }
}
