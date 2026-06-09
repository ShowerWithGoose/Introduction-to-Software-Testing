package parser.func;

import parser.block.Block;

public class MainFuncDef {
    private final Block block;

    public MainFuncDef(Block block) {
        this.block = block;
    }

    public String toString() {
        return "INTTK int\nMAINTK main\nLPARENT (\nRPARENT )\n"
                + this.block.toString() + "<MainFuncDef>\n";
    }
}
