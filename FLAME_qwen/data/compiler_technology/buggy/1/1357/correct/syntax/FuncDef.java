package syntax;

import lexer.LexType;
import logger.Logger;

public class FuncDef {
    public static final LexType[] FIRST = FuncType.FIRST;

    private final FuncType funcType;
    private final String name;
    private final FuncFParams funcFParams;
    private final Block block;

    public FuncDef(FuncType funcType, String name, FuncFParams funcFParams, Block block) {
        this.funcType = funcType;
        this.name = name;
        this.funcFParams = funcFParams;
        this.block = block;
        Logger.logGood("<FuncDef>\n");
    }
}
