package frontend.SyntaxTree;

import java.util.ArrayList;

public class Block {
    private ArrayList<BlockItem> blockItems;

    public Block() {
        this.blockItems = new ArrayList<>();
    }

    public void addBlockItem(BlockItem blockItem) {
        this.blockItems.add(blockItem);
    }
}
