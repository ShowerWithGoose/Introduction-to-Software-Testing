package node;

import frontend.Parser;

import java.util.ArrayList;

public class Block {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.Block;
    private ArrayList<BlockItem> blockItemList;

    public Block(ArrayList<BlockItem> blockItemList) {
        this.blockItemList = blockItemList;
    }

    public ArrayList<BlockItem> getBlockItemList() {
        return blockItemList;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        for (BlockItem blockItem : blockItemList) {
            ret.append("\n").append(blockItem);
        }
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }

}
