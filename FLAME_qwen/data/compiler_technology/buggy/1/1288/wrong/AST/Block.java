package AST;

import java.util.ArrayList;

public class Block {
    private ArrayList<BlockItem> blockItems = new ArrayList<>();
    public Block(ArrayList<BlockItem> blockItems) {
        this.blockItems=(blockItems);
    }
}
