package frontend.parseApart.NodeDef.Normal;

import frontend.parseApart.NodeDef.Block;

public class MainFuncDef {

    private Block block;

    public MainFuncDef() {}

    public void setBlock(Block block) {
        this.block = block;
    }

    public String returnSymbolType() {
        String string = "<MainFuncDef>";
        return string;
    }
}
