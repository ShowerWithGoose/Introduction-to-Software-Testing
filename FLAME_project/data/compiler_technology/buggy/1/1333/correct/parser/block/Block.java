package parser.block;

import java.util.ArrayList;

public class Block{
    private final ArrayList<BlockItem> blockItems;

    public Block() {
        this.blockItems = new ArrayList<>();
    }

    public void addBlockItem(BlockItem blockItem) {
        this.blockItems.add(blockItem);
    }

    public String toString() {
        StringBuilder str = new StringBuilder("LBRACE {\n");
        for (BlockItem blockItem : this.blockItems) {
            str.append(blockItem.toString());
        }
        str.append("RBRACE }\n<Block>\n");
        return str.toString();
    }
}
