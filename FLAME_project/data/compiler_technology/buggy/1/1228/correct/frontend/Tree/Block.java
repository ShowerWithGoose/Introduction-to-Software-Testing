package frontend.Tree;

import java.util.ArrayList;

public class Block {
    private ArrayList<BlockItem> blockItems;
    int line;

    public Block(ArrayList<BlockItem> blockItems, int line) {
        this.blockItems = blockItems;
        this.line = line;
    }

    public ArrayList<BlockItem> getBlockItems() {
        return blockItems;
    }

    public int getLine() {
        return line;
    }
}
