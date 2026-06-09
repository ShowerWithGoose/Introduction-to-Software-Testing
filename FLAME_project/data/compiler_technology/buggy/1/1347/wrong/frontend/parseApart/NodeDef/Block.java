package frontend.parseApart.NodeDef;

import frontend.parseApart.NodeDef.Normal.Stmt;
import frontend.parseApart.NodeDef.Stmts.BlockItem;

import java.util.ArrayList;

public class Block {
    private ArrayList<BlockItem> blockItems = new ArrayList<>();

    public Block() {

    }

    public void setBlockItems(BlockItem blockItem) {
        this.blockItems.add(blockItem);
    }

    public String returnSymbolType() {
        String string = "<Block>";
        return string;
    }
}
