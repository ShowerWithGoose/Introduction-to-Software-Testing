package syntax;

import lexer.LexType;
import logger.Logger;

public class Block {
    public static final LexType[] FIRST = {
            LexType.LBRACE
    };

    private final BlockItem[] blockItems;

    public Block(BlockItem[] blockItems) {
        this.blockItems = blockItems;
        Logger.logGood("<Block>\n");
    }
}
