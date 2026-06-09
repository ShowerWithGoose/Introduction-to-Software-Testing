package syntax;

import lexer.LexType;
import logger.Logger;

public class MainFuncDef {
    public static final LexType[] FIRST = {
            LexType.INTTK
    };

    private final Block block;

    public MainFuncDef(Block block) {
        this.block = block;
        Logger.logGood("<MainFuncDef>\n");
    }
}
