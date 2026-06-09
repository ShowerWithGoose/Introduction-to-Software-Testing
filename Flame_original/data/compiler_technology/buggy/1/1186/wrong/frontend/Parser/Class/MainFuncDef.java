package frontend.Parser.Class;

import java.util.ArrayList;

public class MainFuncDef {
    private Block block;

    public MainFuncDef(Block block, ArrayList<String> outputList) {
        this.block = block;
        outputList.add("<MainFuncDef>");
    }
}
