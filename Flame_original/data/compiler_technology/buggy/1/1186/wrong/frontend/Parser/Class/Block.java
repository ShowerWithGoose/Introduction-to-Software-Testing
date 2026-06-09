package frontend.Parser.Class;

import java.util.ArrayList;

public class Block {
    private ArrayList<BlockItem> blockItems;

    public Block(ArrayList<BlockItem> blockItems,ArrayList<String> outputList) {
        this.blockItems = blockItems;
        outputList.add("<Block>");
    }

    public boolean getResult() {
        if(!blockItems.isEmpty()){
            return blockItems.get(blockItems.size()-1).getResult();
        }
        return false;
    }
}
